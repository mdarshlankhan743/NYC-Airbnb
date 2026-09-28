(() => {
  'use strict';

  /* -----------------------------------------------------
     Config
  ----------------------------------------------------- */
  const DEFAULT_API = 'https://nyc-airbnb-udi5.onrender.com/';
  const STORAGE_KEY = 'afterdark.apiUrl';

  // The classic NYC Airbnb schema trains room_type as three classes.
  // sklearn's LabelEncoder sorts them alphabetically, which is the order
  // predict_proba returns them in — update ROOM_TYPES if your model differs.
  const ROOM_TYPES = [
    {
      key: 'Entire home/apt',
      icon: '<path d="M3 10.5 12 3l9 7.5"/><path d="M5 9.5V20a1 1 0 0 0 1 1h4v-6h4v6h4a1 1 0 0 0 1-1V9.5"/>'
    },
    {
      key: 'Private room',
      icon: '<rect x="4" y="3" width="16" height="18" rx="1.5"/><path d="M15 12h.01"/>'
    },
    {
      key: 'Shared room',
      icon: '<circle cx="8" cy="8" r="3"/><circle cx="16" cy="8" r="3"/><path d="M2 20c0-3 2.5-5 6-5s6 2 6 5M10 20c0-3 2.5-5 6-5s6 2 6 5"/>'
    }
  ];

  const NEIGHBOURHOODS = {
    'Manhattan': ['Harlem', 'East Village', 'Upper West Side', 'Chelsea', 'Midtown', 'Financial District', 'Hell\'s Kitchen', 'Greenwich Village'],
    'Brooklyn': ['Williamsburg', 'Bedford-Stuyvesant', 'Bushwick', 'Park Slope', 'Crown Heights', 'Greenpoint', 'Flatbush'],
    'Queens': ['Astoria', 'Long Island City', 'Flushing', 'Ridgewood', 'Jamaica', 'Sunnyside'],
    'Bronx': ['Mott Haven', 'Riverdale', 'Fordham', 'Concourse'],
    'Staten Island': ['St. George', 'Tompkinsville', 'Stapleton']
  };

  const SAMPLE = {
    neighbourhood_group: 'Brooklyn',
    neighbourhood: 'Williamsburg',
    latitude: 40.71455,
    longitude: -73.95765,
    price: 120,
    minimum_nights: 2,
    number_of_reviews: 45,
    reviews_per_month: 1.8,
    calculated_host_listings_count: 1,
    availability_365: 210
  };

  /* -----------------------------------------------------
     Elements
  ----------------------------------------------------- */
  const form = document.getElementById('predictForm');
  const predictBtn = document.getElementById('predictBtn');
  const errorBanner = document.getElementById('errorBanner');

  const boroughPicker = document.getElementById('boroughPicker');
  const neighbourhoodGroupInput = document.getElementById('neighbourhood_group');
  const neighbourhoodInput = document.getElementById('neighbourhood');
  const neighbourhoodList = document.getElementById('neighbourhoodList');

  const settingsBtn = document.getElementById('settingsBtn');
  const settingsPanel = document.getElementById('settingsPanel');
  const apiUrlInput = document.getElementById('apiUrl');

  const useLocationBtn = document.getElementById('useLocationBtn');
  const fillSampleBtn = document.getElementById('fillSampleBtn');
  const resetBtn = document.getElementById('resetBtn');

  const stateEmpty = document.getElementById('stateEmpty');
  const stateLoading = document.getElementById('stateLoading');
  const stateError = document.getElementById('stateError');
  const stateErrorDetail = document.getElementById('stateErrorDetail');
  const stateDone = document.getElementById('stateDone');

  const resultIcon = document.getElementById('resultIcon');
  const resultLabel = document.getElementById('resultLabel');
  const resultConfidence = document.getElementById('resultConfidence');
  const probList = document.getElementById('probList');

  /* -----------------------------------------------------
     Load-in reveal + ambient lights
  ----------------------------------------------------- */
  requestAnimationFrame(() => document.body.classList.add('is-ready'));

  const lightsWrap = document.getElementById('lights');
  const LIGHT_COUNT = 26;
  for (let i = 0; i < LIGHT_COUNT; i++) {
    const dot = document.createElement('span');
    dot.style.left = Math.random() * 100 + '%';
    dot.style.top = Math.random() * 70 + '%';
    dot.style.animationDelay = (Math.random() * 4) + 's';
    dot.style.background = Math.random() > 0.5 ? 'var(--gold)' : 'var(--teal)';
    dot.style.boxShadow = `0 0 6px 1px ${Math.random() > 0.5 ? 'var(--gold)' : 'var(--teal)'}`;
    lightsWrap.appendChild(dot);
  }

  /* -----------------------------------------------------
     API endpoint settings
  ----------------------------------------------------- */
  apiUrlInput.value = localStorage.getItem(STORAGE_KEY) || DEFAULT_API;

  settingsBtn.addEventListener('click', () => {
    const open = settingsPanel.classList.toggle('is-open');
    settingsBtn.setAttribute('aria-expanded', String(open));
  });
  document.addEventListener('click', (e) => {
    if (!settingsPanel.contains(e.target) && !settingsBtn.contains(e.target)) {
      settingsPanel.classList.remove('is-open');
      settingsBtn.setAttribute('aria-expanded', 'false');
    }
  });
  apiUrlInput.addEventListener('change', () => {
    const val = apiUrlInput.value.trim().replace(/\/$/, '');
    localStorage.setItem(STORAGE_KEY, val || DEFAULT_API);
  });

  /* -----------------------------------------------------
     Borough chips + neighbourhood suggestions
  ----------------------------------------------------- */
  boroughPicker.addEventListener('click', (e) => {
    const chip = e.target.closest('.borough-chip');
    if (!chip) return;
    [...boroughPicker.children].forEach(c => c.classList.remove('is-active'));
    chip.classList.add('is-active');
    const value = chip.dataset.value;
    neighbourhoodGroupInput.value = value;
    neighbourhoodGroupInput.dispatchEvent(new Event('change'));

    neighbourhoodList.innerHTML = '';
    (NEIGHBOURHOODS[value] || []).forEach(n => {
      const opt = document.createElement('option');
      opt.value = n;
      neighbourhoodList.appendChild(opt);
    });
  });

  /* -----------------------------------------------------
     Convenience buttons
  ----------------------------------------------------- */
  useLocationBtn.addEventListener('click', () => {
    // Random plausible point within the five boroughs' bounding box —
    // a quick way to populate coordinates for a test listing.
    const lat = (40.50 + Math.random() * (40.92 - 40.50)).toFixed(6);
    const lon = (-74.25 + Math.random() * (-73.70 - -74.25)).toFixed(6);
    document.getElementById('latitude').value = lat;
    document.getElementById('longitude').value = lon;
  });

  fillSampleBtn.addEventListener('click', () => {
    Object.entries(SAMPLE).forEach(([key, val]) => {
      const el = document.getElementById(key);
      if (el) el.value = val;
    });
    const chip = [...boroughPicker.children].find(c => c.dataset.value === SAMPLE.neighbourhood_group);
    if (chip) chip.click();
    neighbourhoodInput.value = SAMPLE.neighbourhood;
  });

  resetBtn.addEventListener('click', () => showState('empty'));

  /* -----------------------------------------------------
     Result state machine
  ----------------------------------------------------- */
  function showState(name) {
    [stateEmpty, stateLoading, stateError, stateDone].forEach(el => el.hidden = true);
    ({ empty: stateEmpty, loading: stateLoading, error: stateError, done: stateDone }[name]).hidden = false;
  }

  /* -----------------------------------------------------
     Validation
  ----------------------------------------------------- */
  function validate(data) {
    const errors = [];
    const numeric = ['latitude', 'longitude', 'price', 'minimum_nights', 'number_of_reviews',
      'reviews_per_month', 'calculated_host_listings_count', 'availability_365'];

    numeric.forEach(key => {
      const el = document.getElementById(key);
      const val = data[key];
      const isEmpty = val === '' || val === null || Number.isNaN(val);
      el.classList.toggle('is-invalid', isEmpty);
      if (isEmpty) errors.push(key);
    });

    if (!data.neighbourhood_group) errors.push('neighbourhood_group');
    if (!data.neighbourhood) {
      neighbourhoodInput.classList.add('is-invalid');
      errors.push('neighbourhood');
    } else {
      neighbourhoodInput.classList.remove('is-invalid');
    }

    return errors;
  }

  document.querySelectorAll('.field input').forEach(input => {
    input.addEventListener('input', () => input.classList.remove('is-invalid'));
  });

  /* -----------------------------------------------------
     Submit
  ----------------------------------------------------- */
  form.addEventListener('submit', async (e) => {
    e.preventDefault();
    errorBanner.classList.remove('is-visible');

    const payload = {
      neighbourhood_group: neighbourhoodGroupInput.value,
      neighbourhood: neighbourhoodInput.value.trim(),
      latitude: parseFloat(document.getElementById('latitude').value),
      longitude: parseFloat(document.getElementById('longitude').value),
      price: parseFloat(document.getElementById('price').value),
      minimum_nights: parseInt(document.getElementById('minimum_nights').value, 10),
      number_of_reviews: parseInt(document.getElementById('number_of_reviews').value, 10),
      reviews_per_month: parseFloat(document.getElementById('reviews_per_month').value),
      calculated_host_listings_count: parseInt(document.getElementById('calculated_host_listings_count').value, 10),
      availability_365: parseInt(document.getElementById('availability_365').value, 10),
    };

    const errors = validate(payload);
    if (errors.length) {
      errorBanner.textContent = 'Fill in every field before predicting — highlighted above.';
      errorBanner.classList.add('is-visible');
      return;
    }

    const base = (localStorage.getItem(STORAGE_KEY) || DEFAULT_API).replace(/\/$/, '');

    predictBtn.classList.add('is-loading');
    showState('loading');

    try {
      const res = await fetch(`${base}/predict`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify(payload)
      });

      if (!res.ok) {
        const detail = await res.text();
        throw new Error(`Server responded ${res.status}: ${detail.slice(0, 160)}`);
      }

      const result = await res.json();
      renderResult(result);
      showState('done');

    } catch (err) {
      stateErrorDetail.textContent = err.message.includes('Failed to fetch')
        ? `Couldn't connect to ${base}. Is the FastAPI server running and CORS-enabled?`
        : err.message;
      showState('error');
    } finally {
      predictBtn.classList.remove('is-loading');
    }
  });

  /* -----------------------------------------------------
     Render prediction
  ----------------------------------------------------- */
  function renderResult(result) {
    const label = result.Predicted_room_type;
    const probs = result.Probability || [];

    const meta = ROOM_TYPES.find(r => r.key === label);
    resultIcon.innerHTML = `<svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="1.6">${meta ? meta.icon : '<circle cx="12" cy="12" r="9"/>'}</svg>`;
    resultLabel.textContent = label;

    const topProb = probs.length ? Math.max(...probs) : null;
    resultConfidence.innerHTML = topProb !== null
      ? `Confidence <strong>${(topProb * 100).toFixed(1)}%</strong>`
      : '';

    probList.innerHTML = '';
    const labels = probs.length === ROOM_TYPES.length
      ? ROOM_TYPES.map(r => r.key)
      : probs.map((_, i) => `Class ${i + 1}`);

    probs.forEach((p, i) => {
      const row = document.createElement('div');
      row.className = 'prob-row' + (p === topProb ? ' is-top' : '');
      row.innerHTML = `
        <div class="prob-row__top"><span>${labels[i]}</span><span>${(p * 100).toFixed(1)}%</span></div>
        <div class="prob-row__track"><div class="prob-row__fill"></div></div>
      `;
      probList.appendChild(row);
      requestAnimationFrame(() => {
        setTimeout(() => {
          row.querySelector('.prob-row__fill').style.width = (p * 100) + '%';
        }, 40 + i * 90);
      });
    });
  }

})();

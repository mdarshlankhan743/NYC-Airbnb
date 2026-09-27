import streamlit as st
import joblib


# Load trained model
model = joblib.load("logistic_model.pkl")

# Load TF-IDF vectorizer
tfidf = joblib.load("tfidf_vectorizer.pkl")


# Page settings
st.set_page_config(
    page_title="EmotionAI",
    page_icon="🧠",
    layout="wide"
)


# Title
st.title("🧠 EmotionAI")

st.write("AI-powered emotion detection using NLP and Logistic Regression")


# Text input
text = st.text_area(
    "Enter your text",
    placeholder="Example: I am feeling really happy today!",
    height=150
)


# Button
if st.button("✨ Analyze Emotion"):

    if text.strip() == "":
        st.warning("Please enter some text.")

    else:

        # Convert text into TF-IDF
        text_tfidf = tfidf.transform([text])

        # Predict emotion
        prediction = model.predict(text_tfidf)

        # Display result
        st.success(
            f"Detected Emotion: {prediction[0]}"
        )
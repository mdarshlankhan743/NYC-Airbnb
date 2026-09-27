for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
             bd=j-i;
             hg=min(arr[i],arr[j]);
            mx=max(mx,bd*hg);
        }
    } cout<< mx; 
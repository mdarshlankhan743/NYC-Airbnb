#include<bits/stdc++.h>
using namespace std;
int main() {
    int arr[]={3,5,6,2,0,8,2};
    int n=sizeof(arr)/4;
    int mx=arr[0];
    for(int i=0;i<=n;i++){
        if (arr[i]> mx) {
            mx=arr[i];
        }
    }
    cout<<mx;

    cout<<endl;
    
    // for min;
    int mn= arr[0];

    for(int i=0;i<=n;i++){
        if (arr[i]< mn) {
            mn=arr[i];
        }
    }
    cout<<mn;

    // int mx=INT_MIN; int mn=INT_MAX;
    // for(int i=0;i<n;i++){
    //     mx=max(mx,arr[i]);
    //     mn=min(mn,arr[i]);
    // }
    // int i=1, j=mx-mn;
    // cout<<j;
}



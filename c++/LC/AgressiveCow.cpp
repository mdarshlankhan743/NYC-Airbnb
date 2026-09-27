#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int n, int c, int mnad ){
    
    int cow=1, laspos=arr[0];
    for(int i=1;i<n;i++){
        if((arr[i]-laspos)>=mnad){
         cow++;
         laspos=arr[i];
        }
        if(cow==c){
            return true;
        }
    }
    return false;
}


int AgressiveCow(vector<int> &arr, int n,int c){
    sort(arr.begin(),arr.end());
    int mx=INT_MIN; int mn=INT_MAX, ans=-1;;
    for(int i=0;i<n;i++){
        mx=max(mx,arr[i]);
        mn=min(mn,arr[i]);
    }
    int i=1, j=mx-mn;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(isPossible(arr,n,c,mid)){
            ans=mid;
            i=mid+1;
        }else{
            j=mid-1;
        }
    } 
    return ans;
}

int main(){
     vector<int> arr={1,2,8,4,9};
     int n=arr.size();
     int c=3;

     cout<< "MINIMUM DISTANCE :"<< AgressiveCow(arr,n,c)<<endl;
     return 0;
}
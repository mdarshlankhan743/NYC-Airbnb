#include<iostream>
using namespace std;
 int main(){
    int arr[]={1,8,6,2,5,4,8,3,7};
    int n=sizeof(arr)/4;
     int mx=0;
     int hg,bd;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //          bd=j-i;
    //          hg=min(arr[i],arr[j]);
    //         mx=max(mx,bd*hg);
    //     }
    // } 
    // cout<< mx;  

    int lp=0; int rg= n-1;
    while(lp<rg){
        bd=rg-lp;
        hg=min(arr[rg],arr[lp]);
        mx=max(mx,bd*hg);
        if(arr[rg]< arr[lp]){
            rg--;
        }else{
            lp++;
        }
    }
    cout<< mx;

}


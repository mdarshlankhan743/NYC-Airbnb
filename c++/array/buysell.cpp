#include<iostream>
using namespace std;
int main(){
    int arr[]={7,1,5,3,6,4};
    int n= sizeof(arr)/4;
    int mx=0;
    int bb=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>mx){
            mx=max(mx,arr[i]-bb);
        }
        bb=min(bb,arr[i]);
    }
    cout<<mx<<" "<<endl;
    cout<<bb<<" "<<endl;
}
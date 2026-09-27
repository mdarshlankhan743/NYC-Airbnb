#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,7};
    int n=sizeof(arr)/4;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    int i=0;
    int j=n-1;
    while(i<j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=arr[temp];
        i++;
        j--;
    }
    cout<<endl;
   // for(int i=0;i<n;i++){
   //     cout<<arr[i]<<" ";
   // }
   for(int a:arr){
    cout<<a<<" ";
   }
}
#include<iostream>
using namespace std;
int main(){
    int arr[]={1,0,2,1,2,0};
    int n=sizeof(arr)/4;

    int mid=0,low=0,high=n-1;
    while(mid<=high){
         if(arr[mid]==0){
             swap(arr[low],arr[mid]);
             low++;
             mid++;
         } else if (arr[mid]==1){
             mid++;
         } else{
             swap(arr[high],arr[mid]);
             high--;
         }
         for(int i=0;i<n;i++){
             cout<<arr[i]<<" ";
         }
         for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
         }
    }
}

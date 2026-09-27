#include<iostream>
using namespace std;
int linearSearch(int arr[],int n,int target){
    for (int i=0;i<n;i++){
       if(arr[i]==target){
         return i;
        }
    }
    return -1;
}
int main(){
    int arr[]={1,2,3,4,5,3,9,0,10};
    int n=sizeof(arr)/4;
    int target;
    cout<<"Enter element to search: "<< endl;
    cin>>target;
    cout<<linearSearch(arr,n,target)<<endl;
    return 0;
}
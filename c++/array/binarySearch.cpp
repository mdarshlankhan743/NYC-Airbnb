#include <iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,5,7,8,9};
    int n=sizeof(arr)/4;
    int tar=8;
    int i=0; int j=n-1;
    while(i<=j){
        int mid=(i+j)/2;
        //mid=i+(j-i)/2;
        if(arr[mid]<tar){
            i=mid+1;
        }else if(arr[mid]>tar){
            j=mid-1;
        }else{
            cout<<"Element "<< arr[mid] <<" found at index :"<< mid<< endl;
            return 0;
        }
    } 
    cout<<"ele not found"<<endl;
    //return 0;
    
}
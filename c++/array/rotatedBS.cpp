#include <iostream>
using namespace std;
int main() {
    int arr[]={4,5,6,7,0,1,2};
    int n=sizeof(arr)/4;
    int tar=0;
    int i=0; int j=n-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        //tar found 
        if( arr[mid]==tar){
            cout<< mid<<endl;
            return 0;
        }
        //left sorted
        if(arr[i]<=arr[mid]){
            if(arr[i]<=tar && tar <= arr[mid]){
                j=mid-1;
            }else{
                i=mid+1;
             }
        }else{
            if(arr[mid]<=tar && tar<=arr[j]){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
    } 
    return 0;
}
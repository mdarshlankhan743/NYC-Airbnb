#include <iostream>
using namespace std;
int main(){
    int arr[]={1,2,2,3,3,4,4,7,7};
    int n=sizeof(arr)/4;
    int i=0,j=n-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        //FOR  case of index 0, n-1 
        if(mid==0 && arr[0]!=arr[1]) return arr[mid];
        if(mid==n-1 && arr[n-1]!=arr[n-2]) return arr[mid];


        if (arr[mid-1]!=arr[mid] && arr[mid+1]!=arr[mid]){
            cout<<arr[mid];
            return 0;
        }

        if(mid%2==0){ // even
            if (arr[mid]==arr[mid-1]){
                j=mid-1;
            }else{
                i=mid+1;
            }
        }else{ //odd
            if(arr[mid-1]==arr[mid]){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
    }
    cout<<"no element found";

}
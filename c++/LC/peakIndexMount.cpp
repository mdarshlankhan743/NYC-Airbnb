#include <iostream>
using namespace std;
int main(){
    int arr[]={0,2,3,6,7,5,4};
    int n=sizeof(arr)/4;
         
                //Binary search
    int i=1,j=n-2;
    while(i<=j){
        int mid=i+(j-i)/2;
        
        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
            cout<<mid<<endl;
            return 0;
        }

        if (arr[mid-1]<arr[mid]){    //mid lies in left: search on right 
            i=mid+1;
        }else{
            j=mid-1;
        }
    }
           //Linear SEarch

    // for(int i=0;i<n;i++){
    //     if(arr[i-1]< arr[i] && arr[i]>arr[i+1] )
    //     cout <<"peak element is :"<< arr[i]<< "\n And Found at index :" << i<< endl;
    // }


               //BRute force::

    // int mx=0;
    // for(int i=0;i<n;i++){
    //     mx=max(mx,arr[i]);
    // }
    // cout<< mx<<endl;
    // return 0;

}



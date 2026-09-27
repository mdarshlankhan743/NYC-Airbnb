#include<iostream>
using namespace std;

//buble sort
void BubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

//selection sort
void SelectionSort(int arr[],int n){
    int (i=0;i<n-1;i++){
        si=i;
        for(intj=i+1;j<n;j++){
            if(arr[j]<arr[si]){
                si=j;
            }
        }
    } swap(arr[i]<arr[si]);
}

//insertion sort
void InsertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
       int cur=arr[i];prev=i-1;
        while(prev >= 0 && arr[prev]>arr[cur]){
            arr[prev+1]=arr[prev];
            prev--;
        }
    }
    arr[prev+1=cur;]
}

//print array
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
    cout<endl;
}
int main(){
    int arr[]={4,2,5,1,2,0,10};
    int n=sizeof(arr)/4;

   // BubbleSort(arr,n);
    //SelectionSort(arr,n);
    InsertionSort(arr,n)
    printarray(arr,n);
    return 0;
}
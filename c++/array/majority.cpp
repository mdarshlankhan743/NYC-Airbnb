#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>nums={1,2,2,1,1,1};
    int n=nums.size();
    for(int val:nums){
        int frq=0;
         for(int ele:nums){
            if(ele==val){
             frq++;
            }
        }
        if (frq>n/2){
           // cout<<"majority element is "<<val<<endl;
            //break;
            return val;
        }
    }
}
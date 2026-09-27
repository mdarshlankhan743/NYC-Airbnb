#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>nums={1,2,3,4};
    int n=nums.size();
    vector<int>ans(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                ans[i] *=nums[j];
            }
        } cout<< ans[i]<<" ";
    }  
}


// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>ans(n,1);

//         for(int i=1;i<n;i++){
//             ans[i]=ans[i-1]*nums[i-1];
//         }
        
//         int suffix = 1;
//         for(int i=n-2;i>=0;i--){
//             suffix*=nums[i+1];
//             ans[i]*=suffix;

//         }
//         return ans;


//         // prefix[0]=1;
//         // for(int i=1;i<n;i++){
//         //     prefix[i]=prefix[i-1]*nums[i-1];
//         // }
//         // vector<int>suffix(n,1);
//         // suffix[n-1]=1;
//         // for(int i=n-2;i>=0;i--){
//         //     suffix[i]=suffix[i+1]*nums[i+1];
//         // }
//         // vector<int>ans(n,1);
//         // for(int i=0;i<n;i++){
//         //     ans[i]=prefix[i]*suffix[i];
//         // }
//         // return ans;

        
//         // int n=nums.size();
//         // vector<int>ans(n,1);
//         // for(int i=0;i<n;i++){
//         //     for(int j=0;j<n;j++){
//         //         if(i!=j){
//         //             ans [i] *=nums[j];
//         //         }
//         //     }
//         // } return ans;
//     }
// };
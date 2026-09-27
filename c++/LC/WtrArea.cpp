class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx=0;
        int hg,bd;
        // for(int i=0;i<height.size();i++){ // for(int ele:height) 
        //     for(int j=i+1;j<height.size();j++){
        //         bd=j-i;
        //          hg=min(height[i],height[j]);
        //         mx=max(mx,hg*bd);
        //     }
        // }
        // return mx;
        int n=height.size();
        int lp=0; int rp=n-1;
        while(lp<rp){
            bd=rp-lp;
            hg=min(height[lp],height[rp]);
            mx=max(mx,bd*hg);
            if(height[rp]<height[lp]){
                rp--;
            }else{
                lp++;
            }
        } return mx; 
    }
};
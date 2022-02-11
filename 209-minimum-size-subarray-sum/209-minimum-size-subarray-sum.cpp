class Solution {
public:
    int minSubArrayLen(int x, vector<int>& nums) {
        int n= nums.size();
        int sm=0, l=0,r=0, len= n+1;
        while(r<n)
        {
            sm+=nums[r++];
            while(sm>=x){
                len= min(len, r-l);
                sm-=nums[l++];
            }
            
        }
        return len==n+1?0:len;
    }
};
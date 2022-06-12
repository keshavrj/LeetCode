class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sm=0,l=0, r=0, n= nums.size(), ans=0;
  
        while(r<n){
            mp[nums[r]]++;
            sm+=nums[r];
            while(mp[nums[r]]>1)
            {
                mp[nums[l]]--;
                sm-=nums[l];
                l++;
            }
            ans= max(ans, sm);
            r++;
        }
        return ans;
    }
};
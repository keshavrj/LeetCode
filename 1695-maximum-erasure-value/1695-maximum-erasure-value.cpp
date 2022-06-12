class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sm,l=0, r=0, n= nums.size(), ans=0;
        vector<int> dp(n,0);
        dp[0]= nums[0];
        for(int i=1;i<n;i++)
            dp[i]= dp[i-1]+nums[i];
        while(r<n){
            mp[nums[r]]++;
            while(mp[nums[r]]>1)
            {
                mp[nums[l]]--;
                l++;
            }
                sm= l>0 ? dp[r]-dp[l-1] : dp[r];
            ans= max(ans, sm);
            r++;
        }
        return ans;
    }
};
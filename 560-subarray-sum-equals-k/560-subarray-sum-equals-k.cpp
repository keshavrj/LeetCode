class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sm=0, cnt=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            sm+=nums[i];
            if(sm==k)cnt++;
            if(mp.find(sm-k)!=mp.end())
                cnt+=mp[sm-k];
            mp[sm]++;
        }
        return cnt;
        
    }
};
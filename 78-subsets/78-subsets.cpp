class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int mx =1<<n;
        vector<vector<int>> ans;
        for(int i=0;i<mx;i++)
        {
            int j= i, k=n-1;
            vector<int> v;
            while(j>0)
            {
                if(j&1)
                    v.push_back(nums[k]);
                j>>=1;
                k--;
            }
            ans.push_back(v);
        }
        return ans;
    }
};
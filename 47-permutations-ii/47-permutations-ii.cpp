class Solution {
public:
    void solve(vector<vector<int>> &res, int n, vector<int> arr, int i)
    {
        if(i==n-1)
        {
            res.push_back(arr);
            return;
        }
        for(int k= i;k<n;k++)
        {
            if(i!=k && arr[i]==arr[k])continue;
            swap(arr[i], arr[k]);
            solve(res, n,arr, i+1);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        solve(res,nums.size(), nums, 0);
        return res;
    }
};
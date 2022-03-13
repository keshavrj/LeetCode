class Solution {
public:
    void solve(vector<int> &arr,vector<vector<int>> &ans, vector<int> &v, int target, int i)
    {
        if(target==0 )
        {
            ans.push_back(v);
            return;
        }
        while(i<arr.size() && target-arr[i]>=0)
        {
            v.push_back(arr[i]);
            solve(arr, ans, v, target-arr[i], i);
            i++;
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
     sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        vector<vector<int>> ans;
        solve(candidates , ans, v, target, 0);
        return ans;
    
        }
};
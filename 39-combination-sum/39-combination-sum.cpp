class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int> &arr, int curr, vector<int> &ans, int target){
        if(target<0)return;
        if(target==0)
        {
            res.push_back(ans);
            return;
        }
        for(int i= curr;i<arr.size();i++)
        {
            // if(i>curr && arr[i]==arr[i-1])continue;
            ans.push_back(arr[i]);
            solve(arr, i, ans, target-arr[i]);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> ans;
        sort(arr.begin(), arr.end());
        solve(arr,0,ans,target);
        return res;
    }
};
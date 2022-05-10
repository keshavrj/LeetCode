class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int> &ans, int k, int target, int curr)
    {
        if(ans.size()>k)return;
        if(ans.size()==k && target==0){
            res.push_back(ans);
            return;
        }
        for(int i= curr;i<=9;i++)
        {
            ans.push_back(i);
            solve(ans,k,target-i, i+1);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans;
        solve(ans,k,n,1);
        return res;
    }
};
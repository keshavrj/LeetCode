class Solution {
public:
    void solve(int n, int k, int curr, vector<int> &t, vector<vector<int>> &ans){
        if(k==0)
        {
            ans.push_back(t);
            return;
        }
        for(int i=curr;i<=n;i++)
        {
            t.push_back(i);
            solve(n,k-1,i+1,t,ans);
            t.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> t;
        solve(n,k,1,t, ans);
        return ans;
    }
};
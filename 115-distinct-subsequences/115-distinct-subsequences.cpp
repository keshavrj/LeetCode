class Solution {
public:
    vector<vector<int>> dp;
    int solve(string &s, string &t, int n, int m){
        if(m==0)return 1;
        if(n==0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        if(s[n-1]==t[m-1])
            return dp[n][m]= solve(s,t,n-1,m-1)+solve(s,t,n-1,m);
        return dp[n][m]= solve(s,t,n-1,m);
    }
    int numDistinct(string s, string t) {
        int n= s.size(), m= t.size();
        dp.resize(n+1, vector<int> (m+1,-1));
        return solve(s,t,n,m);
    }
};
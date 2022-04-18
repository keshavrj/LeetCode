class Solution {
public:
    int dp[501][501];
    int solve(string &s1, string &s2, int n, int m)
    {
        if(n==0 || m==0)
            return max(n,m);
        if(dp[n][m]!=-1)return dp[n][m];
        if(s1[n-1]==s2[m-1])
            return dp[n][m]= solve(s1,s2,n-1,m-1);
        return dp[n][m]= 1+min(solve(s1,s2,n-1,m), solve(s1,s2,n,m-1));
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof dp);
        int n=word1.size(), m= word2.size();
        return solve(word1,word2,n,m);
    }
};
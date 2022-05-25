class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=n;
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i]=dp[1][i]=1;// length 0 and ending at i;
            }
        for(int i=2;i<=n;i++)
        {
            for(int j= i;j<=n;j++){
                if(s[j-1]==s[j-i] and dp[i-2][j-1]==1) // length i-2 and ending at j-1;
                { dp[i][j]=1;
                  cnt++;
                 }
            }
        }
        return cnt;
    }
};
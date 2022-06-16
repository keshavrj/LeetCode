class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.size();
        int dp[n+1][n+1]; //length*ending_point
        memset(dp, 0, sizeof dp);
        for(int i=0;i<=n;i++)
            dp[0][i]=dp[1][i]=1;
        // dp[1][0]=0; //INVALID
        int len=1, end=1;
        for(int i=2;i<=n;i++)
        {
            for(int j= i;j<=n;j++) //of length i, ending at j;
            {
                if(dp[i-2][j-1]==1 && s[j-i]==s[j-1])
                    dp[i][j]=1, len=i, end=j;
            }
        }
        string ans="";
        for(int i= end-len;i<end;i++)
            ans+=s[i];
        
        return ans;
    }
};
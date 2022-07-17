class Solution {
public:
    int row, col;
    int dir[5]={0,1,0,-1,0};
    int dp[51][51][51];
    int dfs(int r, int c, int k){
        
        if(r<0 || r==row || c<0 || c==col)return 1;
        if(k==0)return 0;
        if(dp[r][c][k]!=-1)return dp[r][c][k];
        int ans=0;
        for(int i=0;i<4;i++){
            ans = (ans+dfs(r+dir[i], c+dir[i+1], k-1))%1000000007;
        }
        return dp[r][c][k]=ans;
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        row=m, col=n;
        memset(dp,-1,sizeof dp);
        return dfs(startRow,startColumn,maxMove);
    }
};
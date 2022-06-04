class Solution {
public:
    const int inf= 1e9;
    int dp[201][201];
    int solve(vector<vector<int>> &grid, int n, int m){
        if(n==0 && m==0)
            return grid[n][m];
        if(n<0 || m<0)return inf;
        if(dp[n][m]!=-1)return dp[n][m];
        return dp[n][m]= grid[n][m]+ min(solve(grid, n-1, m), solve(grid,n,m-1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size(), m= grid[0].size();
        memset(dp,-1,sizeof dp);
        return solve(grid,n-1,m-1);
    }
};
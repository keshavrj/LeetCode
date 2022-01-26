class Solution:
    def solve(self,m,n,dp,i,j):
        if i>m or j>n:
            return 0
        if i==m and j==n:
            dp[i][j]=1
            return dp[i][j]
        if dp[i][j]!=-1:
            return dp[i][j]
        dp[i][j]= self.solve(m,n,dp,i+1,j)+ self.solve(m,n,dp,i,j+1)
        return dp[i][j]
    def uniquePaths(self, m: int, n: int) -> int:
        @cache
        def dfs(i, j):
            if i >= m or j >= n:      return 0
            if i == m-1 and j == n-1: return 1
            return dfs(i+1, j) + dfs(i, j+1)
        return dfs(0, 0)
        
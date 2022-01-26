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
        dp=[[-1 for i in range(n+1)] for j in range(m+1)]
        return self.solve(m,n,dp,1,1)
        
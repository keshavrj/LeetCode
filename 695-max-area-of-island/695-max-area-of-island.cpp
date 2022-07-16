class Solution {
public:
    bool isValid(int x, int y, int n, int m){
        return x>-1 && x<n && y>-1 && y<m;
    }
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(isValid(i,j,grid.size(), grid[0].size()) && grid[i][j]==1){
            grid[i][j]=0;
            return 1+dfs(grid,i+1, j)+dfs(grid,i-1, j)+dfs(grid,i, j+1)+dfs(grid,i, j-1);
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m= grid[0].size(), ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1)ans= max(ans, dfs(grid,i,j));
        return ans;
    }
};
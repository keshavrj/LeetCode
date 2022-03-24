// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  int n, m;
  bool vis[501][501];
    // Function to find the number of islands.
    
    int dx[8]= {1,0,-1,0,-1,1,-1,1};
    int dy[8]= {0,1,0,-1,-1,1,1,-1};
    
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        
        if(i<0 or i>=n or j<0 or j>=m or vis[i][j] or grid[i][j]=='0')return;
        vis[i][j]=1;
        for(int x=0;x<8;x++)
        {
            dfs(grid, i+dx[x],j+dy[x]);
        }
        
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n= grid.size(), m= grid[0].size();
        memset(vis, false, sizeof vis);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                    dfs(grid,i, j), cnt++;
            }
        }
        
        return cnt;
        
        
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends
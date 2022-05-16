class Solution {
public:
    bool isValid(int x,int y, int n){
        return x>=0 && y>=0 && x<n && y<n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        int dx[]= {0,1,1,1,0,-1,-1,-1};
        int dy[]= {1,1,0,-1,-1,-1,0,1};
        queue<pair<int,int>> q;
        if(grid[0][0] or grid[n-1][n-1])return -1;
        else q.push({0,0});
        grid[0][0]=1;
        while(!q.empty())
        {
            int x=q.front().first, y= q.front().second;
            q.pop();
            for(int i=0;i<8;i++)
            {
                int X= x+dx[i], Y=y+dy[i];
                if(isValid(X,Y,n) && grid[X][Y]==0){
                    grid[X][Y]=grid[x][y]+1;
                    q.push({X,Y});
                }
                
            }
        }
        return grid[n-1][n-1]?grid[n-1][n-1]:-1;
    }
};
class Solution {
public:
   int a[4][2]={{1,0},{0,1},{0,-1},{-1,0}};

int minimumEffortPath(vector<vector<int>>& hts) {
    
    // multiset<pair<int,int>>ms;
     queue<pair<int,int>>ms;
    
    int n=hts.size();
    int m=hts[0].size();
    vector<vector<int>>eff(n,vector<int>(m,INT_MAX));
    
    // ms.insert({0,0});
     ms.push({0,0});
    eff[0][0]=0;
    
    while(ms.size()>0)
    {
        // pair<int,int>p=*ms.begin();
         pair<int,int>p=ms.front();
        
       
        int x=p.first;
        int y=p.second;
        
        // ms.erase(ms.begin());
        ms.pop();

        
        for(int i=0;i<4;i++)
        {
            int nx=x+a[i][0];
            int ny=y+a[i][1];
            
            if(nx>=0 && ny>=0 && nx<n && ny<m)
            {
                int newEff=max(abs(hts[x][y]-hts[nx][ny]),eff[x][y]);
                
                if(newEff<eff[nx][ny])
                {
                    eff[nx][ny]=newEff;
                    // ms.insert({nx,ny});
                    ms.push({nx,ny});
                }
            }
        }
    }
    
    return eff[n-1][m-1];
    
}
};
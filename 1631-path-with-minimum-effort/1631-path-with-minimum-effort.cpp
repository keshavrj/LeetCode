class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size(), m= h[0].size(); 
        vector<vector<int>> cost(n,vector<int> (m,INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        pq.push({0,0,0}); //effort,i,j; effort is to maintain heap 
        cost[0][0]= 0;
        //Dijkstra
        int dir[5]= { -1, 0, 1, 0, -1};
        while(!pq.empty())
        {
            int i=pq.top()[1], j= pq.top()[2];
            pq.pop();
            if(i==n-1 && j==m-1)
                return cost[n-1][m-1];
      
            for(int d=0;d<4;d++)
            {
                int X = i+dir[d], Y= j+dir[d+1];
                if(X>=0 && X<n && Y>=0 && Y<m)
                {
                    int new_eff= max(cost[i][j], abs(h[i][j]-h[X][Y]));
                        if(new_eff<cost[X][Y])
                        {
                            cost[X][Y]= new_eff;
                            pq.push({new_eff,X,Y});
                        }
                }
            }
                
            
        }
        return cost[n-1][m-1];
    }
};
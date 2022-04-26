class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& pt) {
        int i=0,ans=0, c=0,n= pt.size();
        vector<bool> vis(n, 0);
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        while(++c<n) // n-1 paths in total for a MST;
        {
            vis[i]=1;
            for(int j=0;j<n;j++)
            {
                if(!vis[j])
                    pq.push({(abs(pt[j][0]-pt[i][0])+abs(pt[j][1]-pt[i][1])), j});
            }
            while(vis[pq.top().second])pq.pop();
            ans+=pq.top().first;
            i= pq.top().second;
            pq.pop();
        }
        return ans;
    }
};
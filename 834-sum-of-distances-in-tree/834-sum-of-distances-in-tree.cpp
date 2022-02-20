class Solution {
public:
    int N;
    vector<int> adj[30002];
    int dis[30002], res[30002], subsize[30002];
    void preprocessing(int node, int par)
    {
        subsize[node]=1;
        for(int child:adj[node])
        {
             if(child!=par)
            {
                preprocessing(child,node);
                subsize[node]+= subsize[child];
                dis[node]+= dis[child]+ subsize[child];
            }
        }
    }

    void dfs(int node, int par)
    {
        res[node]= res[par]- dis[node]- subsize[node] + N - subsize[node] +                     dis[node];
         for(int child:adj[node])
            if(child!=par)dfs(child, node);
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N=n;
        for(int i=0;i<N;i++)
            adj[i].clear();
        for(int i=0;i<n-1;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        preprocessing(0,-1);// it will give us result when tree is rooted at 0;      
        res[0]=dis[0];
        for(int i:adj[0])
            dfs(i,0);
        
        vector<int> ans;
        for(int i=0;i<n;i++)
            ans.push_back(res[i]);
        
        return ans;
    }
};
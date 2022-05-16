// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    int vis[100005];
    bool dfs(int node, vector<int> adj[])
    {
        vis[node]= 1;
        for(int i:adj[node])
        {
            if(!vis[i])
            {
                if(dfs(i,adj))return true;
            }
            if(vis[i]==1)return true;
        }
        vis[node]=2;
        return false;
    }
    bool bfs(int V, vector<int> adj[])
    {
        vector<int> in_degree(V,0);
        for(int i=0;i<V;i++)
            for(auto x:adj[i])
                in_degree[x]++;
        queue<int> q;
        for(int i=0;i<V;i++)if(in_degree[i]==0)q.push(i);
        int cnt=1;
        while(!q.empty())
        {
            int u= q.front();q.pop();
            for(int x:adj[u])
            if(--in_degree[x]==0){
                q.push(x);
                cnt++;
            }
        }
        return cnt!=V;
        
    }
    bool isCyclic(int V, vector<int> adj[]) {
        return bfs(V,adj);
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
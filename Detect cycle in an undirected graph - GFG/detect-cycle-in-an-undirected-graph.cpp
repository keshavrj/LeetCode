// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool vis[100005]={0};
    bool bfs(int node, vector<int> &par, vector<int> adj[])
    {
        queue<int> q;
        q.push(node);
        vis[node]=1;
        while(!q.empty())
        {
            int u= q.front();q.pop();
            for(int v:adj[u])
            {
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                    par[v]=u;
                }
                else if(par[u]!=v)return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
          memset(vis, 0, sizeof vis);
          vector<int> par(V+1, -1);
        for(int i=0;i<V;i++)
            {
                if(!vis[i])
                    if(bfs(i,par,adj))return true;
            }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    int vis[100004];
    bool dfs(int node, vector<int> adj[])
    {
        vis[node]=1;
        for(int child:adj[node])
        {
            if(!vis[child]){if( dfs(child, adj))return true;}
            else if(vis[child]==1)return true;
        }
        vis[node]= 2; //It represents that the current node is no longer under execution 
                        //and there is no cycle through it.
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        memset(vis,0, sizeof vis);
       for(int i=0;i<V;i++)
        {
            if(!vis[i])
                if(dfs(i, adj))return true;
        }
        return false;
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
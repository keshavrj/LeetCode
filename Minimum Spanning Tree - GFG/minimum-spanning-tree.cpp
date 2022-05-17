// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<bool> vis(n,0);
        int ans=0;
        vector<int> key(n,INT_MAX);
        using pii = pair<int,int> ;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,0}); //dist, node;
        key[0]=0;

        // for(int i=0;i<n-1;i++)
        while(!pq.empty())
        {
            int u= pq.top().second;
            pq.pop();
            vis[u]=true;
            for(auto x:adj[u]){
                int v= x[0];
                int w= x[1];
                if(vis[v]==0 and w<key[v]){
                    pq.push({w,v});
                    key[v]=w;
                }
            }
        }
        ans= accumulate(key.begin(),key.end(),0);
        return ans;
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
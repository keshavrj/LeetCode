// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph
    void dfs1(int node, vector<int> adj[], stack<int> &st, vector<bool> &vis)
    {
        vis[node]=1;
        for(int i:adj[node])
        {
            if(!vis[i])
                dfs1(i,adj,st,vis);
        }
        st.push(node);
    }
    void dfs2(int node, vector<int> adj[], vector<bool> &vis)
    {
        // cout<<node<<" ";
        vis[node]=1;
        for(int i:adj[node])
            if(!vis[i])dfs2(i,adj,vis);
    }
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<int> rev[V];
        vector<bool> vis(V,false);
        int cnt=0;
        for(int i=0;i<V;i++)
            if(!vis[i])dfs1(i,adj,st,vis);
        //reversing Edges:
        for(int i=0;i<V;i++)
        {
            for(int j:adj[i])
                rev[j].push_back(i);
        }
        vis.assign(V,false);
        while(!st.empty())
        {
            int x= st.top();
            st.pop();
            if(!vis[x]){
                dfs2(x,rev,vis);
                cnt++;
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
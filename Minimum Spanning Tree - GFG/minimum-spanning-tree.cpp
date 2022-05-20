// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int findpar(int x, vector<int> &parent){
        if(x== parent[x])return x;
        return parent[x]= findpar(parent[x], parent);
    }
    void unionn(int x, int y, vector<int> &parent, vector<int> &rank){
        int u= findpar(x,parent);
        int v= findpar(y,parent);
        if(rank[u]<rank[v])parent[u]=v;
        else if(rank[v]<rank[u])parent[v]=u;
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // kruskals;
        vector<int> parent(n), rank(n,0);
        for(int i=0;i<n;i++)parent[i]=i;
        int cost=0;
        using pii = pair<int,int> ;
        priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
        for(int i=0;i<n;i++)
        {
            for(auto &x:adj[i])
            {
                int node= x[0];
                int wt=x[1];
                pq.push({wt,{i,node}});
                
            }
        }
        while(!pq.empty())
        {
            auto x= pq.top();pq.pop();
            int w= x.first;
            int u= x.second.first;
            int v= x.second.second;
            if(findpar(u,parent)!=findpar(v,parent)){
                    unionn(u,v,parent,rank);
                    cost+=w;
            }
        }
        return cost;
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
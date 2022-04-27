class Solution {
public:
    void dfs(int node, vector<int>&pos, vector<int> &vis, vector<vector<int>> &gr)
    {
        vis[node]=1;
        pos.push_back(node);
        for(int i:gr[node])
        {
            if(!vis[i])
                dfs(i,pos,vis,gr);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n= s.size();
        vector<vector<int>> gr(n);
        for(int i=0;i<pairs.size();i++)
        {
            gr[pairs[i][0]].push_back(pairs[i][1]);
            gr[pairs[i][1]].push_back(pairs[i][0]);
        }
        string ans= s;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vector<int> pos;
                dfs(i,pos,vis,gr);
                string tmp="";
                for(auto id:pos)
                    tmp+=s[id];
                sort(pos.begin(), pos.end());
                sort(tmp.begin(), tmp.end());
                for(int x=0;x<pos.size();x++)
                    ans[pos[x]]= tmp[x];
                
            }
        }
        return ans;
        
    }
};
class Solution {
public:
    int col[101];
    bool dfs(int node, int c, vector<vector<int>> &gr)
    {
        col[node]= c;
        for(int i:gr[node])
        {  
            if(col[i]==-1)
            {
                if(dfs(i,c^1,gr)==false)return false;
            }
            else if(col[node]==col[i])return false;
         }
        return true;
    }
    bool isBipartite(vector<vector<int>>& gr) {
        memset(col, -1, sizeof col);
        for(int i=0;i<gr.size();i++)
        {
            if(col[i]==-1)
            {
                if(dfs(i,1,gr)==false)return false;
            }
        }
        return true;
    }
};
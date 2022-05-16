class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n= mat.size(), m=mat[0].size();
        for(int i=1;i<n;i++)
        {
            for(int j= 0;j<m;j++)
            {
                mat[i][j]+= min({mat[i-1][max(0,j-1)], mat[i-1][j], mat[i-1][min(m-1,j+1)]});
            }
        }
        return *min_element(mat[n-1].begin(), mat[n-1].end());
    }
};
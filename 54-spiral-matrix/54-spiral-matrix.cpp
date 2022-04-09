class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
    int n= mat.size(), m= mat[0].size();
    vector<int> v;
    int direction=1, left=0, right= m-1, top= 0, bottom=n-1;
        while(v.size()<(n*m))
        {
            if(direction==1)
            {
                for(int i=left;i<=right;i++)v.push_back(mat[top][i]);
                top++;
                direction = 2;
            }
            else if(direction==2)
            {
                for(int i=top;i<=bottom;i++)v.push_back(mat[i][right]);
                right--;
                direction=3;
            }
            else if(direction ==3)
            {
                for(int i=right;i>=left;i--)v.push_back(mat[bottom][i]);
                bottom--;
                direction=4;
            }
            else if(direction==4)
            {
                for(int i= bottom;i>=top;i--)v.push_back(mat[i][left]);
                left++;
                direction=1;
            }
        }
        return v;
        
    }
};
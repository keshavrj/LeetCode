class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int> (n));
        int left=0, right=n-1,top=0,bottom=n-1,val=1, dir =1;
        while(val<=n*n)
        {
            if(dir==1)
            {
                for(int i=left;i<=right;i++,val++)
                {
                    ans[top][i]=val;
                }
                top++;
                dir=2;
            }
            else if(dir==2)
            {
                for(int i=top;i<=bottom;i++,val++)
                    ans[i][right]=val;
                dir=3;
                right--;
            }
            else if(dir==3)
            {
                for(int i=right;i>=left;i--,val++)
                    ans[bottom][i]= val;
                bottom--;
                dir=4;
            }
            else if(dir==4)
            {
                for(int i=bottom;i>=top;i--,val++)
                {
                    ans[i][left]=val;
                }
                left++;
                dir=1;
            }
        
        }
        return ans;
    }
};
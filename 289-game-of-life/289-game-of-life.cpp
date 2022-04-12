class Solution {
public:
    bool isvalid(int n, int m , int i, int j)
    {
        return (i>=0 && i<n && j>=0 && j<m);
    }
    void gameOfLife(vector<vector<int>>& arr) {
        int dx[]= {1,0,-1,0,1,-1, 1, -1};
        int dy[]= {0,1,0,-1 ,1,-1, -1, 1};
        int n= arr.size(), m= arr[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int cnt=0;
                for(int k= 0;k<8;k++)
                {
                    if(isvalid(n,m,i+dx[k], j+dy[k]) && arr[i+dx[k]][j+dy[k]]>0)
                        cnt++;
                }
                // cout<<cnt<<endl;
                if(arr[i][j]==1 && (cnt==2 || cnt==3))continue;
                else if(arr[i][j]==1 && (cnt>3 || cnt<2))
                    arr[i][j]=2; //2 means dead;
                else if(arr[i][j]==0 && cnt==3)
                    arr[i][j]= -1;
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]==2)arr[i][j]=0;
                else if(arr[i][j]==-1)arr[i][j]=1;
            }
    }
};
class Solution {
public:
   vector<int> leftRow, lowerD, upperD; 
    void solve(int &ans, vector<string> &q, int col, int n){
        if(col==n){
            ans++;
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(leftRow[row]==0 && lowerD[col+row]==0 && upperD[n-1+ col-row]==0){
                q[row][col]='Q';
                leftRow[row]=1;
                lowerD[col+row]=1; 
                upperD[n-1+ col-row]=1;
                solve(ans,q,col+1,n);
                 q[row][col]='.';
                leftRow[row]=0;
                lowerD[col+row]=0; 
                upperD[n-1+ col-row]=0;
                
            }
        }
    }
     int totalNQueens(int n){
        vector<string> q(n,string(n,'.'));
    int ans=0;
        leftRow.resize(n,0);
        lowerD.resize(2*n-1,0);
        upperD.resize(2*n-1,0);
        solve(ans,q,0,n);
        return ans;
    }
};
  
class Solution {
public:
    vector<int> leftRow, lowerD, upperD;
    bool isValid(int row, int col, vector<string> &q){
        //checking cols;
        for(int i=col;i>=0;i--)
            if(q[row][i] == 'Q') return false;
        
        // check left diagonal
        for(int i=row,j=col;i>=0&&j>=0;i--,j--)
            if(q[i][j] == 'Q') return false;
        
        //check right diagonal
        for(int i=row,j=col;i<q.size() && j>=0;i++,--j)
            if(q[i][j] == 'Q') return false;
        
        return true;
    }
    void solve(vector<vector<string>> &ans, vector<string> &q, int col, int n){
        if(col==n){
            ans.push_back(q);
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
    vector<vector<string>> solveNQueens(int n) {
        vector<string> q(n,string(n,'.'));
        vector<vector<string>> ans;
        leftRow.resize(n,0);
        lowerD.resize(2*n-1,0);
        upperD.resize(2*n-1,0);
        solve(ans,q,0,n);
        return ans;
    }
};
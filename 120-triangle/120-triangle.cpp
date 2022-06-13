class Solution {
public:
    int solve(vector<vector<int>> &triangle,vector<vector<int>> &dp, int row, int col){
        if(row==triangle.size())return 0;
        if(dp[row][col]!=INT_MAX)return dp[row][col];
        return dp[row][col]= triangle[row][col]+ min(solve(triangle, dp, row+1, col), solve(triangle, dp, row+1, col+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size(), m= triangle.back().size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,INT_MAX));
        return solve(triangle, dp, 0, 0);
    }
};
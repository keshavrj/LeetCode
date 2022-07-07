class Solution {
public:
    // int dp[201][101][101];
    // bool solve(string &s1, string &s2, string &s3, int n, int m, int k){
    //     if(k<1 && n<1 && m<1)return true;
    //     if(k<1)return false;
    //     if(n>0 && m>0 && dp[k][n][m]!=-1)return dp[k][n][m];
    //  if(n>0 && s1[n]==s3[k] && m>0 && s2[m]==s3[k] ) 
    //         return dp[k][n][m] = (solve(s1, s2, s3, n-1, m, k-1) || solve(s1,s2,s3,n,m-1,k-1));
    //     if(n>0 && s3[k-1]==s1[n-1])
    //         return dp[k][n][m] = solve(s1,s2,s3,n-1,m,k-1);
    //     if(m>0 && s3[k-1]==s2[m-1])
    //         return dp[k][n][m]= solve(s1,s2,s3,n,m-1,k-1);
    //     return false;
    // }
     bool helper(string& s1, string& s2, string &s3, int l1, int l2, int l3, vector<vector<int>>&dp) {
        if(l1<0 && l2<0 && l3<0) {
            return true;
        }
        if(l1>=0 && l2>=0 && dp[l1][l2]!=-1) {
            return dp[l1][l2];
        }
        if(l1>=0 && s1[l1]==s3[l3] && l2>=0 && s2[l2]==s3[l3] ) {
            return dp[l1][l2] = (helper(s1, s2, s3, l1-1, l2, l3-1, dp) || helper(s1, s2, s3, l1, l2-1, l3-1, dp));
        }
        else if(l1>=0 && s1[l1]==s3[l3])
            return helper(s1, s2, s3, l1-1, l2, l3-1, dp);
        
        else if(l2>=0 &&s2[l2]==s3[l3])
            return helper(s1, s2, s3, l1, l2-1, l3-1, dp);
        
        else return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size())
			return false;
        vector<vector<int>>dp(s1.size()+1, (vector<int>(s2.size()+1, -1)));
        // memset(dp, -1, sizeof(dp));
        return helper(s1, s2, s3,s1.size()-1, s2.size()-1, s3.size()-1, dp);
    }
};
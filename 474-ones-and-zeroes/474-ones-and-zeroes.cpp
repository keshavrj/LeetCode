class Solution {
public:
    int dp[602][101][101];
    int solve(vector<string>&strs, int z, int o, int n){
        if(n==0 or (z+o)==0)return dp[n][z][o]= 0;
        if(dp[n][z][o]!=-1)return dp[n][z][o];
        int ones= count(strs[n-1].begin(), strs[n-1].end(), '1');
        int zeroes= strs[n-1].size()-ones;
        if(z>=zeroes and o>=ones){
            return dp[n][z][o]= max(1+solve(strs,z-zeroes, o-ones, n-1), solve(strs, z, o, n-1));
        }
        return dp[n][z][o]= solve(strs, z,o,n-1);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof dp);
        int len= strs.size();
        return solve(strs,m,n,len);
    }
};
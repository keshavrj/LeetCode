class Solution {
public:
    int dp[13][10004];
    int solve(vector<int>& coins, int target, int n){
        
        if(target==0)
            return 0;
        if(n==0)
            return dp[n][target]= INT_MAX-1;
        
        if(dp[n][target]!=-1)
            return dp[n][target];
 
        if(coins[n-1]<=target)
            return dp[n][target]= min(1+solve(coins,target-coins[n-1], n), 
                                      solve(coins, target, n-1));
            return dp[n][target]= solve(coins, target, n-1);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1, sizeof dp);
        int n= coins.size();
        int ans= solve(coins, amount, n);
        return ans== INT_MAX-1 ? -1 : ans;
    }
};
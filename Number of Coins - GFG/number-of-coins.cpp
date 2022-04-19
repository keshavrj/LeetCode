// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int inf= INT_MAX-1;
	int solve(int arr[], int n, int sum, vector<vector<int>> &dp)
	{
	    if(sum==0)return 0;
	    if(n==0)return inf;
	    if(dp[n][sum]!=-1)return dp[n][sum];
	   // dp[n][sum]=inf;
	    if(arr[n-1]<=sum)
	     return dp[n][sum]= min(1+solve(arr, n,sum-arr[n-1], dp), solve(arr, n-1,sum, dp));
	    return dp[n][sum] = solve(arr, n-1, sum, dp);
	    
	}
	int minCoins(int coins[], int n, int sum) 
	{ 
	    vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
	    int x= solve(coins,n,sum,dp);
	    return x>=inf ? -1 : x ;
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
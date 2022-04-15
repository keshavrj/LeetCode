// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	const int mod= 1e9+7;
	long long solve(int arr[], int n, int sum, vector<vector<long long>> &dp)
	{
	    if(sum==0)return dp[n][sum]=1LL;
	    if(n==0)return dp[n][sum]= 0LL;
	    if(dp[n][sum]!=-1)return dp[n][sum];
	    if(arr[n-1]<=sum)
	       return dp[n][sum]= (solve(arr, n-1,sum-arr[n-1], dp)+solve(arr,n-1,sum, dp))%mod;
	    return dp[n][sum]= solve(arr, n-1, sum, dp)%mod;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<long long>> dp(n+1,vector<long long> (sum+1,0));
        for(int i=0;i<sum+1;i++)
            dp[0][i]=0;
        for(int i=0;i<n+1;i++)
            dp[i][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(arr[i-1]<=j)
                    dp[i][j]=(dp[i-1][j-arr[i-1]]+dp[i-1][j])%mod;
                else dp[i][j]= dp[i-1][j];
            }
        }
        return dp[n][sum]%mod;
        
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
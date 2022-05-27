// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	const int inf= 1e9;
	int solve(int arr[], int n, int w, vector<vector<int>>&dp){
	    if(n==0)return w==0?0:inf;
	    if(dp[n][w]!=-1)return dp[n][w];
	    if(n<=w && arr[n-1]!=-1)
	        return dp[n][w]= min(arr[n-1]+solve(arr, n,w-n, dp), solve(arr, n-1, w, dp));
    	return dp[n][w]= solve(arr, n-1,w,dp);    
	}
	int minimumCost(int cost[], int n, int w) 
	{ 
        vector<vector<int>> dp(n+1, vector<int> (w+1,-1));
        int ans= solve(cost, n,w,dp);
        // for(int i=0;i<=n;i++){
        //     for(int j= 0;j<=w;j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return ans==inf ? -1 :ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
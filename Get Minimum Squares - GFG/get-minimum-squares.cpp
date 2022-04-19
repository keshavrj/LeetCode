// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int solve(int n, vector<int> &dp)
	{
	    if(n==0)return 0;
	    if(dp[n]!=-1)return dp[n];
	    int ans= INT_MAX;
	    for(int i=sqrt(n);i>=1;i--)
	        ans = min(ans, 1+solve(n-i*i, dp));
	        
	    return dp[n]=ans;
	}
	int MinSquares(int n)
	{
	    vector<int> dp(n+1, -1);
	    return solve(n,dp);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
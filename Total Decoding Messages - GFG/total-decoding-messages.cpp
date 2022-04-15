// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    int dp[10002];
	    const int mod= 1e9+7;
	    int solve(string &s, int n)
	    {
	        if(s[0]=='0')return 0;
	        if(n==0 or n==1)return 1;
	        if(dp[n]!=-1)return dp[n];
	        int cnt=0;
	        if(s[n-1]>'0')
	           cnt = solve(s,n-1)%mod;
	       if(s[n-2]=='1' or (s[n-1]<'7' && s[n-2]=='2'))
	          cnt= (cnt +solve(s,n-2))%mod;
	        return dp[n]=cnt;
	        
	           
	    }
		int CountWays(string str){
		memset(dp,-1,sizeof dp);
		int n= str.size();
		return solve(str,n)%mod;
		    
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
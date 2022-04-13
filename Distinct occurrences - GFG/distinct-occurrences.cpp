// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    
    int64_t mod= 1e9+7;
    int64_t dp[8002][102];
    int solve(string &S, string &T, int n, int m)
    {
        if(m==0)return 1LL;
        if(n==0)return 0LL;
        if(dp[n][m]!=-1)return dp[n][m];
        
        if(S[n-1]==T[m-1])
             {
                 dp[n][m]= solve(S,T,n-1,m-1)+solve(S,T,n-1,m);
                return dp[n][m]%=mod;
                 
             }
        dp[n][m]= solve(S,T,n-1,m);
        return dp[n][m]%=mod;
        
    }
    int subsequenceCount(string S, string T)
    {
        int m= T.size(), n= S.size();
        memset(dp,-1,sizeof dp);
        solve(S,T,n,m);
        return dp[n][m]%mod;
    }
};
 


// { Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}  // } Driver Code Ends
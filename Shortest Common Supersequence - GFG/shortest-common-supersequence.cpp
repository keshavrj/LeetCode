// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int dp[101][101];
    int solve(string &X, string &Y, int m, int n)
    {
        if(m==0 || n==0)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        if(X[m-1]==Y[n-1])
            return dp[m][n]= 1+solve(X,Y,m-1,n-1);
        return dp[m][n]= max(solve(X,Y,m-1,n), solve(X,Y,m,n-1));
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        memset(dp,-1,sizeof dp);
        return m+n-solve(X,Y,m,n);
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}

  // } Driver Code Ends
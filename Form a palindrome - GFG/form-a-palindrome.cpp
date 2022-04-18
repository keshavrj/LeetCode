// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int dp[1001][1001];
    int solve(string &a, string &b, int n, int m)
    {
        if(n==0 || m==0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        if(a[n-1]==b[m-1])
            return dp[n][m]=1+solve(a,b,n-1,m-1); 
        return dp[n][m]= max(solve(a,b,n-1,m), solve(a,b,n,m-1));

    }
    int countMin(string S1){
        string S2= S1;
        reverse(S2.begin(), S2.end());
        int n= (int)S1.length();
        memset(dp,-1,sizeof dp);
        return n-solve(S1,S2,n,n);
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends
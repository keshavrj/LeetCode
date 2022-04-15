// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int dp[1001][1001];
    long long int solve(int arr[], int n, int m)
    {
        if(n==0)return 0ll;
        if(m==0)return 1ll;
        // if(m<0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        if(arr[n-1]<=m)
            return dp[n][m]= solve(arr,n, m-arr[n-1])+solve(arr, n-1, m);
        return dp[n][m]= solve(arr, n-1, m);
    }
    long long int count(int S[], int m, int n) {
        
        memset(dp,-1,sizeof dp);
        return solve(S,m,n);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends
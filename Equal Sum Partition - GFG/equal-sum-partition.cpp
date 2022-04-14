// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template in C++


class Solution
{
    public:
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
    bool solve(int arr[], int n, int sm, vector<vector<int>> &dp)
    {
        if(sm==0)return true;
        if(n==0)return false;
        if(dp[n][sm]!=-1)return dp[n][sm];
        if(arr[n-1]<=sm)
            return dp[n][sm]=solve(arr, n-1, sm-arr[n-1], dp)||solve(arr,n-1,sm,dp);
        return dp[n][sm]= solve(arr, n-1, sm,dp);
    }
    bool findPartition(int a[], int n)
    {
        int sm= accumulate(a,a+n,0);
        if(sm&1)return false;
        vector<vector<int>> dp(n+1,vector<int> (sm,-1));
        return solve(a,n,sm/2, dp);
    }
};

// { Driver Code Starts.
int main() {
    
    //taking total testcases
    int tc;
    cin >> tc;
    while (tc--) {
        
        //taking size of array
        int n, i;
        cin >> n;
        int a[n];
        
        //inserting elements in the array
        for (i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        //calling findPartition() function and
        //printing "YES", if it returns true
        //else "NO"
        if (ob.findPartition(a, n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
  // } Driver Code Ends
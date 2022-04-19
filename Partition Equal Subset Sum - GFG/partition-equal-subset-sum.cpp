// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int arr[], int n, int sum, vector<vector<int>> &dp)
    {
        if(sum==0)return 1;
        if(n==0)return 0;
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        if(arr[n-1]<=sum)
            return dp[n][sum]= solve(arr, n-1, sum-arr[n-1], dp) ||solve(arr, n-1, sum, dp);
        return dp[n][sum]= solve(arr, n-1, sum, dp);
        
    }
    int equalPartition(int N, int arr[])
    {
        int sum=accumulate(arr, arr+N,0);
        if(sum&1)return 0;
        int tot= sum/2;
        vector<vector<int>> dp(N+1, vector<int> (tot+1, -1));
        return solve(arr, N, tot, dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
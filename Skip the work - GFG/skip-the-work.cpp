// { Driver Code Starts
#include <iostream>
using namespace std;

 // } Driver Code Ends

#include<bits/stdc++.h>
class Solution
{
  public:
    // long long int dp[1000003];
    // long long solve(int arr[], int n)
    // {
    //     if(n<=0)return 0ll;
    //     if(dp[n]!=-1)return dp[n];
    //     return dp[n]= max((long long)arr[n-1]+solve(arr,n-2), solve(arr, n-1));
        
    // }
    int minAmount(int a[] , int n)
    {
        // memset(dp,-1,sizeof dp);
        // long long int sm=accumulate(A,A+N,0ll);
        // return (int)(sm-solve(A,N));
        if(n==1)return 0;
        if(n==2)return min(a[0],a[1]);
        // int dp[n+2]={0};
        for(int i=2;i<n;i++)
        {
            a[i]= a[i] + min(a[i-1], a[i-2]);
        }
        return min(a[n-1],a[n-2]);
        
    }
    };

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
        {
            int n;
            cin>>n;
            int arr[n];
            for(int i = 0;i<n;i++)
                cin>>arr[i];
            Solution ob;    
            cout<<ob.minAmount(arr,n)<<endl;    
        }
}  // } Driver Code Ends
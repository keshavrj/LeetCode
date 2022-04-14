// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int dp[10002];
    int solve(int n, int x, int y, int z){
        if(n==0)return 0;
        if(n<0)return INT_MIN;
        if(dp[n]!=-1)return dp[n];
        return dp[n]= 1+max({solve(n-x,x,y,z),solve(n-y,x,y,z),solve(n-z,x,y,z) });
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        memset(dp,-1,sizeof dp);

        return max(0, solve(n,x,y,z));
        
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends
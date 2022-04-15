// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> m)
    {
        int dp[N+2][N+2]={{0}};
        for(int i=N;i>0;i--)
        {
            dp[N][i]=m[N-1][i-1];
        }
        for(int i=N-1;i>=1;i--)
        {
            for(int j=N;j>=1;j--)
            {
                dp[i][j]=m[i-1][j-1]+max({dp[i+1][j], dp[i+1][j+1], dp[i+1][j-1]});
            }
        }
        int ans= -1;
        for(int i=1;i<=N;i++)
        ans= max(ans, dp[1][i]);
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
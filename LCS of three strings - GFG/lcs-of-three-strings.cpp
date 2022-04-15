// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int dp[101][101][101];
int solve(string &A, string &B, string &C, int n1, int n2, int n3)
{
    if(!n1 or !n2 or !n3)return 0;
    if(dp[n1][n2][n3]!=-1)return dp[n1][n2][n3];
    if(A[n1-1]==B[n2-1] && B[n2-1]==C[n3-1])
        return dp[n1][n2][n3]= 1+ solve(A,B,C,n1-1,n2-1,n3-1);
    else{
        int a= solve(A,B,C,n1-1,n2,n3);
        int b= solve(A,B,C,n1,n2-1,n3);
        int c= solve(A,B,C,n1,n2,n3-1);
        return dp[n1][n2][n3]= max(a,max(b,c));
    }
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    
    memset(dp,-1,sizeof dp);
    return solve(A,B,C,n1,n2,n3);    
    
}
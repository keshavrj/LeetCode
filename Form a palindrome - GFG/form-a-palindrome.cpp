// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int dp[502][502];
    int solve(string &s1, string &s2, int n, int m)
    {
        if(!n or !m)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        if(s1[n-1]==s2[m-1])
            return dp[n][m]= 1+ solve(s1, s2, n-1, m-1);
        return dp[n][m]= max(solve(s1,s2, n-1, m), solve(s1,s2,n, m-1));
        
    }
    int findMinInsertions(string s1){
        string s2= s1;
        memset(dp, -1, sizeof dp);
        reverse(s2.begin(), s2.end());
        return s1.size()- solve(s1,s2,s1.size(), s1.size());
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
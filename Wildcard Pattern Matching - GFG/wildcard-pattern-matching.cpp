// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
int dp[201][201];
    bool solve(string &pattern, string &str, int n, int m)
    {
        if(n==0 and m==0)return 1;
        if(n==0)
            return 0;
        if(m==0)
        {
            while(n>0)
                {
                    if(pattern[n-1]!='*')
                        return 0;
                    n--;
                }
            return 1;
        }
        if(dp[n][m]!=-1)return dp[n][m];
        if(pattern[n-1]==str[m-1] || pattern[n-1]=='?')
            return dp[n][m]= solve(pattern,str,n-1,m-1);
        if(pattern[n-1]=='*')
            return dp[n][m]= solve(pattern,str,n-1,m) || solve(pattern,str,n,m-1);
        return dp[n][m]=0;
    }
    int wildCard(string pattern,string str)
    {
        memset(dp,-1,sizeof dp);
        int n= pattern.size(), m= str.size();
        solve(pattern,str,n,m);
        return dp[n][m];
    }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}
  // } Driver Code Ends
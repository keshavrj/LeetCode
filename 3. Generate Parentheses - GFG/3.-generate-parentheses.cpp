// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(vector<string> &ans, string s, int n, int m)
    {
        if(n==0 && m==0)
        {
            ans.push_back(s);
            return;
        }
        if(n>0) solve(ans, s+'(', n-1, m+1);
        if(m>0) solve(ans, s+')', n, m-1);
    }
    vector<string> AllParenthesis(int n) 
    {
        int m=0;
        string s="";
        vector<string> ans;
        solve(ans, s, n, m);
        return ans;
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
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends
// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    void solve(string s, vector<string> &ans,int i, int n)
    {
        if(i==n)
        {
            ans.push_back(s);
            return;
        }
        for(int j=i;j<n;j++)
        {
            swap(s[i], s[j]);
            solve(s,  ans, i+1, n);
            swap(s[i], s[j]);
        }
    }
    vector<string> permute(string s){
       vector<string> ans;
       int n = s.size();
       solve(s, ans,0,  n);
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
		string s;
		cin>>s;
		Solution obj;
		vector<string> ans;
		ans = obj.permute(s);
		sort(ans.begin(), ans.end());
		for(auto x: ans)
		    cout << x << " ";
		
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
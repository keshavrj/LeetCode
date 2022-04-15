// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	set<string> st;
	void solve(string s, int l, int r)
	{
	    if(l==r){
	        st.insert(s);
	        return;
	    }
	    for(int i=l;i<=r;i++)
	    {
	        swap(s[l],s[i]);
	        solve(s,l+1,r);
	        swap(s[l],s[i]);
	    }
	        
	}
		vector<string>find_permutation(string S)
		{
		    vector<string> ans; 
		    int n= S.size();
		    solve(S,0,n-1);
		  //  for(auto i:st)
		  //      cout<<i<<" ";   
		    ans.insert(ans.end(), st.begin(), st.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void solve(vector<vector<int>> &ans, vector<int> &v,vector<int> &arr, int i )
    {
        if(i==arr.size())
        {
            ans.push_back(v);
            return;
        }
        v.push_back(arr[i]);
        solve(ans, v, arr, i+1);
        v.pop_back();
        solve(ans, v, arr, i+1);
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        vector<vector<int> > ans;
        vector<int> v;
        solve(ans, v, A, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends
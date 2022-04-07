// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string LCP(string ar[], int n)
    {
        // sort(ar,ar+n, [](string &a, string &b)
        // {
        //     return a.length()<=b.length();
        // });
        int j=ar[0].size();
        for(int i=1;i<n;i++)
        {
            int k=0;
            while(ar[0][k]==ar[i][k])
                k++;
            // k--;
            j=min(j,k);
            
        // cout<<k<<endl;
        }
        return j<=0? "-1" :  ar[0].substr(0,j);
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
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}  // } Driver Code Ends
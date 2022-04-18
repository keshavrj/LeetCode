// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long karyTree(long long int k, long long int m) {
    int mod= 1e9+7;
    long long ans=1ll;
    // k%=mod;
    while(m)
    {
        if(m&1)
            ans= (ans*k)%mod;
        k= (k*k)%mod;
        m>>=1;
    }
    return ans%mod;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    }
    return 0;
}  // } Driver Code Ends
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int N) {
    if(A[0]==0)return 0;
    if(N<1)return 1;
    int i,max_jump=A[0];
    for(i=1;i<N;i++)
    {
        max_jump= max(max_jump-1, A[i]);
        if(i==N-1)return 1;
        if(max_jump==0)return 0;
    }
    if(i>=N-1)
        return 1;
    return 0;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends
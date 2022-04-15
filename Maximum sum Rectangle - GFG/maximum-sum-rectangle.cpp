// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int kadanes(vector<int> &arr)
    {
        int curr_sum=arr[0], max_sum=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            curr_sum= max(arr[i], curr_sum+arr[i]);
            max_sum= max(max_sum, curr_sum);
        }
        return max_sum;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // int max_left=-1,max_right=-1,max_up=-1,max_down=-1;
        int mx=INT_MIN;
        for(int l=0;l<C;l++)
        {
            vector<int> t(R,0);
            for(int r=l;r<C;r++)
            {
                for(int i=0;i<R;i++)
                {
                    t[i]+=M[i][r];
                }
                mx= max(mx,kadanes(t));
            }
        }
        return mx;
        
        
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends
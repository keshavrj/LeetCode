// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:

    string longestPalin (string s) {
        int n= s.size();
        if(n<2)return s;
        string ans= "";
        ans+=s[0];
        int low, high, max_length=1, start_index=0;
        for(int i=1;i<n-1;i++)
        {
            low= i-1, high= i+1;
            while(high<n && s[i]==s[high])
                high++;
            while(low>=0 && s[i]==s[low])
                low--;
            while(low>=0 && high<n && s[low]==s[high])
                low--, high++;
            
            int length= high-low-1;//low can become-1 and high can become n;
            if(length>max_length)
            {
                max_length= length;
                // start_index=low+1;
                ans= s.substr(low+1,length);
            }
            
        }
        return ans;
        
        
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
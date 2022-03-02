// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int maxLength(string s)
    {
       vector<int> seq;
       seq.push_back(s[0]);
       for(int i=1;i<s.size();i++)
       {
           if(s[i]>seq.back())seq.push_back(s[i]);
           else{
               
               int j= lower_bound(seq.begin(), seq.end(), s[i])- seq.begin();
               seq[j]=s[i];
           }
       }
       return seq.size();
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout << ob.maxLength(S) << endl;
    }
    return 0; 
}  // } Driver Code Ends
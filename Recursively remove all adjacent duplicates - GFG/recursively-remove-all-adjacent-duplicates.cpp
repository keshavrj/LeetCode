// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    string remove(string s){
        int n= s.size();
        if(n==0)return s;
        int i, k=0;
        for(i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])
                s[k++]= s[i-1];
            else{
                while(i<n && s[i]==s[i-1])i++;
            }
        }
        s[k++]= s[i-1];
        if(k!=n)
        {
            return remove(s.substr(0,k));    
        }
        return s;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.remove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends
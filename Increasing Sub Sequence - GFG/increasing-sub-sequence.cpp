// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int maxLength(string s)
    {
        vector<int> dp;
        dp.push_back(s[0]-'a'+1);
        for(int i=1;i<s.size();i++)
        {
            if((s[i]-'a'+1)>dp.back())
                dp.push_back(s[i]-'a'+1);
            else{
                int index= lower_bound(dp.begin(), dp.end(),s[i]-'a'+1)-dp.begin();
                dp[index]= s[i]-'a'+1;
            }
            
        }
        return dp.size();
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
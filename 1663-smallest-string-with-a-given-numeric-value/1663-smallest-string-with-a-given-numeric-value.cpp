class Solution {
public:
    string getSmallestString(int n, int k) {
      string ans(n,'a');
        k-=n;
        for(int i= n-1;i>=0 && k>0;i--)
        {
            // k++;
            
            ans[i]+= min(25, k);
            k-=(ans[i]-'a');
        }
        return ans;
    }
};
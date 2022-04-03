class Solution {
public:
    bool isValid(string &s, int l, int r)
    {
        while(l<r){
        if(s[l]!=s[r])return false;
        l++, r--;
        }
        return true;
    }
    bool validPalindrome(string s1){
      int l= 0, r= s1.size()-1;
        while(l<=r)
        {
            if(s1[l]!=s1[r]){
                return isValid(s1, l+1, r) || isValid(s1, l, r-1);
            }
            l++, r--;
        }
        return true;
        
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, ans=0, hash[256]={0};
        while(r<s.size())
        {
            hash[s[r]]++;
            while(hash[s[r]]>1){
                hash[s[l]]--;
                l++;
            }
            ans= max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};
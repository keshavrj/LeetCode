class Solution {
public:
    bool hasAllCodes(string s, int k) {
        string x= s.substr(0,k);
        unordered_set<string> st;
        st.insert(x);
        for(int i=k;i<s.size();i++)
        {
            x.erase(0,1);
            x+=s[i];
            st.insert(x);
        }
        return st.size()==(1ll<<k);
    }
};
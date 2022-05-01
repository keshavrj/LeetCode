class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a="", b="";
        for(auto i:s)
        {
            if(i=='#' && !a.empty())a.pop_back();
            else if(i!='#') a+=i;
        }
        for(auto i:t)
        {
            if(i=='#' && !b.empty())b.pop_back();
            else if(i!='#')b+=i;
        }
        return a==b;
    }
};
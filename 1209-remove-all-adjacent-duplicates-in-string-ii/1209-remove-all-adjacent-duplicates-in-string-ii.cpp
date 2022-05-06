class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(auto i:s)
        {
            
            if(st.empty() or st.top().first!=i)
                st.push({i,1});
            else 
                st.top().second++;
            
            if(st.top().second==k)
                st.pop();
        }
        s="";
        while(!st.empty())
        {
            string x(st.top().second, st.top().first);
            s=x+s;
            st.pop();
        }
        return s;
    }
};
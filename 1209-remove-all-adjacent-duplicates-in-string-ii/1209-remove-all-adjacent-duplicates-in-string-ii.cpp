class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(auto i:s)
        {
            
            if(st.empty() or st.top().first!=i)
                st.push({i,1});
            else if(!st.empty() && st.top().first==i)
                st.top().second++;
            
            if(st.top().second==k)
                st.pop();
            // if(!st.empty())cout<<st.size()<<st.top().first<<st.top().second<<endl;
            // else cout<<"empty"<<endl;
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
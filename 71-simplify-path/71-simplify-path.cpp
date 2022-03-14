class Solution {
public:
    string simplifyPath(string path) {
        string ans="", temp="";
        stack<string> st;
        for(int i=0;i<path.size();i++)
        {
            if(path[i]=='/')continue;
            temp="";
            while(i<path.size() && path[i]!='/')
            {
                temp+=path[i++];
            }
            if(temp==".")
                continue;
            else if(temp==".." )
            {
                if( !st.empty())
                st.pop();}
            
            else st.push(temp);
                
        }
        while(!st.empty())
        {
            ans= "/"+st.top()+ans;
            st.pop();
        }
        return ans.size()==0 ? "/" :ans;
    }
};
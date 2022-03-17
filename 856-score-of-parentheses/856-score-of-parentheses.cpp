class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int ans=0;
        for(auto i:s)
        {
            if(i=='('){
                st.push(0);
            }
            else{        
            if(st.top()==0)
            {
                st.pop();
                st.push(1);
            }
            else
            {
            
                int tot=0;
                while(st.top()!=0)
                {
                    tot+=st.top();
                    st.pop();
                }
                st.pop();
                st.push(2*tot);
                
                
            }}
            
        }
        while(!st.empty())
            ans+=st.top(), st.pop();
        return ans;
    }
};
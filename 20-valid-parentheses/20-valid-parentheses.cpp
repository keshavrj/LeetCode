class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s){
            if(i=='(' or i=='{' or i=='[')st.push(i);
            else if(st.empty())return false;
            else if(i=='}'){
                    if(st.top()=='{')st.pop();
                    else return false;
            }
            else if(i==')'){
                    if(st.top()=='(')st.pop();
                    else return false;
            }        
                        else if(i==']'){
                    if(st.top()=='[')st.pop();
                    else return false;
            }
        
        }
        return st.empty();
        
    }
};
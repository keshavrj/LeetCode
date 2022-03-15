class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if(s.size()==0)return "";
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                cnt++;
            else if(s[i]==')' and cnt==0)
                s[i]='!';
            else if(s[i]==')')cnt--;
        }
        cnt=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]==')')cnt++;
            else if(s[i]=='(')
            {
                if(cnt==0)s[i]='!';
                else cnt--;
            }
        }
        string ans="";
        for(auto i:s)
            if(i!='!')ans+=i;
        
        return ans;
    }
};
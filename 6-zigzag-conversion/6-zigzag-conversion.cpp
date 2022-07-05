class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1)return s;
        vector<string> v(numRows,"");
        for(int i=0, row=0, dir=1; i<s.size() ;i++){
            v[row]+=s[i];
            if(row==0)dir=1;
            else if(row == numRows-1)dir=-1;
            row+=dir;
        }
        string ans="";
        for(auto x:v)ans+=x;
        return ans;
    }
};
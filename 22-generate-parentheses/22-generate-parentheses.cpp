class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        solve(v,"", 0, n);
        return v;
        
    }
    void solve(vector<string> &v, string s, int m, int n)
    {
        if(m==0 && n==0){
            v.push_back(s);
            return;
        }
        if(n>0)
            solve(v,s+"(", m+1, n-1);
        if(m>0)solve(v, s+")", m-1, n);
    }
};
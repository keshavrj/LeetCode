class Solution {
public:

    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(int i:nums)
            v.push_back(to_string(i));
        sort(v.begin(), v.end(), [](string &a, string &b){return a+b>b+a;});
        string ans="";
        for(auto i:v){
            // cout<<i<<" ";
            ans+=i;
        }
        while(ans[0]=='0' && ans.size()>1)
            ans.erase(0,1);
        
        return ans;
    }
};
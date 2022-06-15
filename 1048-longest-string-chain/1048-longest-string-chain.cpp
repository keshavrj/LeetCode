class Solution {
public:
    int dp[1001];
    int longestStrChain(vector<string>& words) {
        memset(dp, -1, sizeof dp);
        sort(words.begin(), words.end(), [](string &a, string &b){return a.size()<b.size();});
        int ans=1;
        for(int i=0;i<words.size();i++)
        {
            ans= max(ans, solve(i, words));
        }
        return ans;
    }
    int solve(int prev, vector<string>& words){
        if(dp[prev]!=-1)return dp[prev];
        int res=1;
        for(int i= prev+1;i<words.size();i++){
            if(words[i].size()-words[prev].size()>1)
                break;
            if(words[i].size()-words[prev].size()==1 && ispredecessor(words[prev], words[i]))
                res= max(res, 1+solve(i,words));
            
        }
        return dp[prev]= res;
    }
    bool ispredecessor(string &a, string &b){
        int i=0;
        for( i=0;i<a.size();i++){
            if(a[i]!=b[i])break;
        }
        for(int x=i, y= i+1; x<a.size();x++, y++){
            if(a[x]!=b[y])return false;
        }
        return true;
    }
    
};
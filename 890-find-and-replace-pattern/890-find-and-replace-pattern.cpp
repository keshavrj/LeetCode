class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern){
        vector<string> ans;
        for(auto word:words){
            
            if(word.size()!=pattern.size())continue;
            
            unordered_map<char, char> mp1, mp2;
            vector<bool> dp(26,false);
            bool flag=1;
            
            for(int i=0;i<word.size();i++){
                if((mp1.find(pattern[i])!=mp1.end() && mp1[pattern[i]]!=word[i]) || (mp2.find(word[i])!=mp2.end() && mp2[word[i]]!=pattern[i] ))
                {
                    flag=0;
                    break;
                }
                else mp1[pattern[i]]=word[i], mp2[word[i]]= pattern[i];
            }
            if(flag)ans.push_back(word);
        }
        return ans;
    }
};
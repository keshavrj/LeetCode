class Solution {
public:
    int lengthOfLIS(vector<int>& s) {
         vector<int> seq;
       seq.push_back(s[0]);
       for(int i=1;i<s.size();i++)
       {
           if(s[i]>seq.back())seq.push_back(s[i]);
           else{
               
               int j= lower_bound(seq.begin(), seq.end(), s[i])- seq.begin();
               seq[j]=s[i];
           }
       }
       return seq.size();
    }
};
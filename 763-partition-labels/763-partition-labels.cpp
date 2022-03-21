class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(256,0), ans;
        for(int i=0;i<s.size();i++)
        {
            last[s[i]]=i;
        }
        
        int max_ind= -1 , curr=0;
        
        for(int i=0;i<s.size();i++)
        {
 
                max_ind= max(max_ind, last[s[i]]);
                if(i==max_ind)
                {
                    ans.push_back(max_ind-curr+1);
                    curr= i+1;
                }
            
        }
        return ans;
    }
};
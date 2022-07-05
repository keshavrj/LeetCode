class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int max_len=0;
        for(int x:nums){
            if(st.find(x-1)!=st.end())continue;
            int j=1;
            while(st.find(x+j)!=st.end())j++;
            max_len= max(max_len, j);
        }
        return max_len;
    }
};
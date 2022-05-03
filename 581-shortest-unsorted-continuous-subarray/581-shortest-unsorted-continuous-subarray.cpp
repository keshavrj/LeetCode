class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // if(nums.size()<=1)return 0;
        vector<int> v= nums;
        sort(v.begin(), v.end());
        int i=0, j= nums.size()-1;
        while(i<nums.size() && nums[i]==v[i])i++;
        while(j>=0 && nums[j]==v[j])j--;
        if(j<=i)return 0;
        return j-i+1;
    }
};
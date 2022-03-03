class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3)return 0;
        int ans=0, curr=0, prev_diff= nums[1]-nums[0];
        for(int i=1;i<nums.size()-1;i++)
        {
            int curr_diff= nums[i+1]-nums[i];
            if(curr_diff==prev_diff)
                curr++;
            else curr=0, prev_diff=curr_diff;
            
            ans+=curr;
        }
        return ans;
    }
};
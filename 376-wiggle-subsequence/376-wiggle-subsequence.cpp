class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans=1, n= nums.size();
        for(int i=0;i<n-1;){
            if(nums[i]>nums[i+1]){
                ans++;
                while(i<n-1 && nums[i]>=nums[i+1])i++;
            }
            else if(nums[i]<nums[i+1])
            {
                ans++;
                while(i<n-1 && nums[i]<=nums[i+1])i++;
            }
            else i++;
        }
        return ans;
    }
};
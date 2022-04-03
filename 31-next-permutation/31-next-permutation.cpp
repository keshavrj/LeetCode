class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n= nums.size();
        int i=0,j;
        for(i=n-2;i>=0;i--)
            if(nums[i]<nums[i+1])break;
        if(i<0)
        {
            reverse(nums.begin(),nums.end());
            return ;
        }
        for(j=n-1;j>i;j--)
        {
            if(nums[j]>nums[i])
            {
                swap(nums[j],nums[i]);
                break;
            }
        }
        // j=b_search(nums,i+1,n-1,nums[i]);
        // swap(nums[j],nums[i]);
        reverse(nums.begin()+i+1, nums.end());
    }
};
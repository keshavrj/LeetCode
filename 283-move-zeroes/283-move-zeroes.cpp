class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0, j=0;i<nums.size() && j<nums.size();i++)
        {
            while(j<nums.size() && (nums[j]==0 || i==j))j++;
            
                if(nums[i]==0 && j<nums.size()){
                nums[i]= nums[j];
                nums[j]=0;
                }
        }
    }
};
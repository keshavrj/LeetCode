class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int pos=-1, val_cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(val_cnt==0){pos=i; val_cnt++;}
            else{
                if(nums[pos]==nums[i])
                    val_cnt++;
                else val_cnt--;
            }
        }
        return nums[pos];
    }
};
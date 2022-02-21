class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_ind=0, cnt=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[maj_ind])
                cnt++;
            else cnt--;
            
            if(cnt==0)
            {
                maj_ind= i;
                cnt=1;
            }
        }
        // int cand=
           return nums[maj_ind];
        
        // cnt=0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i]==cand)
        //         cnt++;
        // }
        
        
    }
};
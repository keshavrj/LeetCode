class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
     sort(nums.begin(), nums.end());
        int res, mn= INT_MAX;
        for(int i=0;i<nums.size()-2;i++)
        {
            int l= i+1, r= nums.size()-1;
            while(l<r)
            {
                int x= nums[i]+nums[l]+nums[r];
                if(abs(x-target)<mn)
                {
                    mn= abs(x-target);
                    res= x;
                }
                if(x==target)return x;
                if(x>target)r--;
                else l++;
            }
        }
        return res;
    }
};
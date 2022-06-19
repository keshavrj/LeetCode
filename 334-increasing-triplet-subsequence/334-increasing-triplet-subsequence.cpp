class Solution {
public:
    bool increasingTriplet(vector<int>& nums){
      
      vector<int> dp;
        dp.push_back(nums[0]);
        for(int x:nums){
            if(x>dp.back())dp.push_back(x);
            else{
                int index= lower_bound(dp.begin(), dp.end(), x)- dp.begin();
                dp[index]= x;
            }
            if(dp.size()==3)
                return true;
        }
        return false;
        
    }
};
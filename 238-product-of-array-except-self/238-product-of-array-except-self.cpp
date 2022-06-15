class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        // vector<int> left(n), right(n), res(n);
        // left[0]=right[0]=1;
        // for(int i=1;i<n;i++)
        // {
        //     left[i]= left[i-1]*nums[i-1];
        //     right[i]= right[i-1]*nums[n-i];
        // }
        // for(int i=0;i<n;i++)
        //     res[i]= left[i]*right[n-1-i];
        // return res;
        vector<int> res(n,1);
        int left=1, right=1;
        for(int i= 0;i<n;i++)
        {
            res[i]*=left;
            left*=nums[i];
            res[n-1-i]*=right;
            right*=nums[n-1-i];
        }
        return res;
    }
};
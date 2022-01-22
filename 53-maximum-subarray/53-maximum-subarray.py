class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curr, ans = 0,-10**5
        for x in nums:
            curr+= x
            ans= max(ans,curr)
            if curr<0:
                curr=0
        return ans;
        
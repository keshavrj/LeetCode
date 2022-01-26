class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        maj_ind=0
        cnt=1
        for i in range(1,len(nums)):
            if nums[i]==nums[maj_ind]:
                cnt+=1
            else:
                cnt-=1
            if cnt==0:
                maj_ind=i;
                cnt=1
        return nums[maj_ind]
        
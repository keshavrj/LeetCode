class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp=dict()
        for i in range(len(nums)):
            if nums[i] not in mp:
                mp[nums[i]]=i
        for i in range(len(nums)):
            x= target-nums[i]
            if x in mp and mp[x]!=i:
                return [i,mp[x]]
        return []
        
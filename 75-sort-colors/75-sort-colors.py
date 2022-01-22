class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        freq=[0]*3
        for i in nums:
            freq[i]+=1
        j=0
        for i in range(3):
            while freq[i]>0:
                nums[j]=i
                j+=1
                freq[i]-=1
    
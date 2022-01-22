class Solution:
    
    def rev(self, nums, ind):
        x=ind
        j=len(nums)-1
        while(x<j):
            nums[x],nums[j]= nums[j], nums[x]
            x+=1
            j-=1
        
            
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n= len(nums)
        i=n-2
        while i>=0:
            if nums[i]<nums[i+1]:
                break;
            i-=1
    
        if i<0:
            self.rev(nums,0)
            return
        for j in range(len(nums)-1,i,-1):
            if nums[j]>nums[i]:
                # self.swap(nums[j],nums[i])
                nums[i],nums[j]= nums[j], nums[i]
                break
        self.rev(nums, i+1)
            
        
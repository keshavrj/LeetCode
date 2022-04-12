#User function Template for python3

class Solution:
    def findOnce(self,arr : list, n : int):
        # Complete this function
        l, r= 0, n-1
        while l<r:
            mid= (l+r)//2;
            if arr[mid]!=arr[mid-1] and arr[mid]!=arr[mid+1]:
                return arr[mid]
            if mid&1:
                if(arr[mid]==arr[mid-1]):
                    l=mid+1
                else: r= mid-1
            else:
                if arr[mid]==arr[mid-1]:
                    r=mid-1
                else:
                    l=mid+1
        
        return arr[l]
                    

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    
    for _ in range(t):
        n = int(input())
        arr = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.findOnce(arr, n))
# } Driver Code Ends
#User function Template for python3
import math as m
class Solution:
    def countSquares(self, N):
        # code here 
        x=int(m.sqrt(N))
        if x*x==N:
            return x-1
        return x

#{ 
#  Driver Code Starts
#Initial Template for Python 3
import math

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        
        ob = Solution()
        print(ob.countSquares(N))
# } Driver Code Ends
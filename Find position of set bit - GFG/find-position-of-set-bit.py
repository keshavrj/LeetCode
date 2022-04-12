#User function Template for python3

class Solution:
    def findPosition(self, N):
        # code here 
        cnt=0
        pos=0
        while N:
            pos+=1
            if N&1:
                cnt+=1
            N>>=1
        if cnt!=1:
            return -1
        return pos
                

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N = int(input())
        
        ob = Solution()
        print(ob.findPosition(N))
# } Driver Code Ends
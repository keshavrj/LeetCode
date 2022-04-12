#User function Template for python3

class Solution:
    #Function to return list containing first n fibonacci numbers.
    def printFibb(self,n):
        # your code here
        if n<2:
            return [1]
        ans=[0]*n
        ff,ss=1,1
        ans[0]=ff
        ans[1]=ss
        for i in range(2,n):
            ff= ff+ss
            ss=ff-ss
            ans[i]=ff
        return ans
        

#{ 
#  Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__ == '__main__': 
    t=int(input())
    for tcs in range(t):
        
        n=int(input())
        res = Solution().printFibb(n)
        for i in range (len (res)):
            print (res[i], end = " ") 
        print()
# } Driver Code Ends
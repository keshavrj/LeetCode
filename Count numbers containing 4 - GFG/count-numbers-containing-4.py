#User function Template for python3

class Solution:
    def countNumberswith4(self, N):
        # code here
        dp=[0]*(N+1)
        def check(dp,i):
            while i:
                if dp[i]:
                    return True
                r=i%10
                if r==4:
                    dp[i]=True
                    return True
                i//=10
            return False
        cnt=0
        for i in range(1, N+1):
            if dp[i]: cnt+=1
            if check(dp,i):
                # dp[i]=True
                cnt+=1
        return cnt
                

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        
        ob = Solution()
        print(ob.countNumberswith4(N))
# } Driver Code Ends
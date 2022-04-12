#User function Template for python3


class Solution:
    def sortRecords(self, a, n):
        # Your code goes here
        a.sort(key=lambda x:x[0])
        a.sort(key=lambda x:x[1])
        # return a
    

#{ 
#  Driver Code Starts
if __name__ == '__main__': 
    
    
    t=int(input())
    for _ in range(0,t):
        n=int(input())
        s=list(map(str,input().split()))
        a=[]
        for i in range(0,2*n,2):
            a.append([s[i],int(s[i+1])])
        ob = Solution()
        ob.sortRecords(a,n)
        for i,j in a:
            print(i+" "+str(j),end=" ")
        print()
        
# } Driver Code Ends
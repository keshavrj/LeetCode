#User function Template for python3

class Solution:
    def shortestUnorderedSubarray(self, a, n):
        #Code here
        flag1,flag2=1,1
        for i in range(n-1):
            if int(a[i])<int(a[i+1]):
                flag1=0
                break
        for i in range(n-1):
            # print(i)
            if int(a[i])>int(a[i+1]):
                flag2=0
                break
        # print(flag2)
        if flag1==1 or flag2==1:
            return 0
        return 3
    
    
    

#{ 
#  Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [x for x in input().strip().split()]
        
        print(Solution().shortestUnorderedSubarray(a, n))
        
        T -= 1


if __name__ == "__main__":
    main()


# } Driver Code Ends
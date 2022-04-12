#User function Template for python3


def find(arr,n,x):
    # code here
    first, last=-1,-1
    l, r= 0, n-1
    while l<=r:
        mid= (l+r)//2;
        if arr[mid]>=x:
            r=mid-1
        else: l=mid+1
    first=l;
    l,r=0,n-1
    while l<=r:
        mid= (l+r)//2;
        if arr[mid]<=x:
            l=mid+1
        else: r=mid-1
    second=r;
    if(second<first):
        return [-1,-1]
    return [first,second]
        
            


#{ 
#  Driver Code Starts
t=int(input())
for _ in range(0,t):
    l=list(map(int,input().split()))
    n=l[0]
    x=l[1]
    arr=list(map(int,input().split()))
    ans=find(arr,n,x)
    print(*ans)
# } Driver Code Ends
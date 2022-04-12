class Solution:
    def gameOfLife(self, arr: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        dx=[1,1,1,0,0,-1,-1,-1]
        dy=[0,1,-1,1,-1,0,1,-1]
        n= len(arr)
        m= len(arr[0])
        def isValid(i,j,n,m):
            if i>=0 and i<n and j>=0 and j<m:
                return True
            return False
        for i in range(n):
            for j in range(m):
                cnt=0
                for k in range(8):
                    if isValid(i+dx[k], j+dy[k], n, m)==True and arr[i+dx[k]][j+dy[k]]>0:
                        cnt+=1
                # print(cnt)
                if arr[i][j]==1 and (cnt<2 or cnt>3):
                    arr[i][j]=2;
                elif arr[i][j]==0 and cnt==3:
                    arr[i][j]=-1
        for i in range(n):
            for j in range(m):
                if arr[i][j]==2:
                    arr[i][j]=0
                elif arr[i][j]==-1:
                    arr[i][j]=1;
        
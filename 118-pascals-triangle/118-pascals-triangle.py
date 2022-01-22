class Solution:
    def generate(self, n: int) -> List[List[int]]:
        ans= []
        for i in range(n):
            t= [1]*(i+1)
            if i==0 or i==1:
                ans.append(t)
                continue;
            for j in range(1,i):
                t[j]=ans[i-1][j-1]+ans[i-1][j];
            ans.append(t)
        
        return ans
                
        
        
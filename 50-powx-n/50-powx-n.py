class Solution:
    def myPow(self, x: float, n: int) -> float:
        m= abs(n)
        res=1
        while m>0:
            if m&1:
                res*=x
            x*=x
            m>>=1
        
        if n>0:
            return res
        return 1/res
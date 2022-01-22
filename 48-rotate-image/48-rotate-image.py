class Solution:
    def rotate(self, m: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m.reverse()
        for i in range(len(m)):
            for j in range(i, len(m)):
                m[i][j], m[j][i]=m[j][i], m[i][j]
        
        # for i in range(len(m)):
        #     m[i].reverse()
        
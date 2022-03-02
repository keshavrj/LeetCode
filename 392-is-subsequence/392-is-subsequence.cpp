class Solution {
public:
    bool isSubsequence(string A, string B) {
         int m=A.size(), n= B.size(), i=0, j=0;
        for(;i<n && j<m; i++)
        {
            if(A[j]==B[i])
                j++;
        }
        return j==m;
    }
};
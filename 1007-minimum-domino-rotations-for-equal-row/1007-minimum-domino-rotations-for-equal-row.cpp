class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int cntA[7]={0}, cntB[7]= {0}, same[7]={0}, n= A.size();
    
        for(int i=0;i<n;i++)
        {
            cntA[A[i]]++;
            cntB[B[i]]++;
            if(A[i]==B[i])same[A[i]]++;
            
        }
        
        for(int i=1;i<=6;i++)
            if(cntA[i]+cntB[i]-same[i]==n)return n- max(cntA[i], cntB[i]);
        
        return -1;
    
    }
};
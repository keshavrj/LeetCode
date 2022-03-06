class Solution {
    public int countOrders(int n) {
         int mod= (int)1e9+7;
        long res=1;
        for(int i=1;i<=n;i++)
        {
            res= (res* (2*i-1)*i)%mod; // (2n-1)*2n ->total purmutation for nth value, delivery will come always after pickup so divide by 2; 
        }
        return (int)res%mod;
    }
}
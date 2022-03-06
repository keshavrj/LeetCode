class Solution {
public:
    int countOrders(int n, long val=1) {
        if(n==0)return (int)val%1000000007;
        return countOrders(n-1,(n*(2*n-1)*val)%1000000007 );
    }
};
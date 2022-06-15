class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n+1,true);
        primes[0]=primes[1]=false;
        for(int i=2;i*i<=n;i++)
        {
            for(int p=i*i;p<=n;p+=i){
                primes[p]=false;
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++)
            if(primes[i])cnt++;
        return cnt;
    }
};
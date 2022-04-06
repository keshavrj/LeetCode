class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        map<long long,long long> mp;
        long long int ans=0, mod= (long long)1e9+7;
        for(int i:arr)mp[i]++;
        for(auto it1:mp)
        {
            for(auto it2:mp)
            {
                int i=it1.first, j= it2.first;
                int k= target-i-j;
                if(i==j && j==k)
                    ans+=(mp[i]*(mp[i]-1)*(mp[i]-2))/6;
                else if(i==j && j!=k)
                    ans+=((mp[i]*(mp[i]-1))/2)* mp[k];
                
                else if(i<j && j<k) ans+= mp[i]*mp[j]*mp[k];
                
                ans%=mod;
            }
        }
        return (int)ans;
    }
};
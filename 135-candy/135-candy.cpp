class Solution {
public: 
    int candy(vector<int>& arr)
    {
        int n= arr.size();
        int ans=0;
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1])dp[i]= dp[i-1]+1;
        }
        ans=dp[n-1];
        for(int i=n-2;i>-1;i--){
            if(arr[i]>arr[i+1])dp[i]= max(dp[i], dp[i+1]+1);
            ans+=dp[i];
        }
        return ans;
    }   
};
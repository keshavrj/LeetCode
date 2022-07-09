class Solution {
public:
    int maxResult(vector<int>& arr, int k) {
        int n= arr.size();
        vector<int> dp(n);
        priority_queue<pair<int,int>> pq;
        pq.push({arr.back(), n-1});
        dp[n-1]= arr.back();
        for(int i=n-2;i>=0;i--){
            while(!pq.empty() && pq.top().second>i+k)
                pq.pop();
            dp[i]=pq.top().first+arr[i];
            pq.push({dp[i],i});
        }
        return dp[0];
    }
};
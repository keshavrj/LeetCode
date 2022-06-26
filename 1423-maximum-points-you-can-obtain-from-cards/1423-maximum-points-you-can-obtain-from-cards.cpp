class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n =arr.size();
        int ans= 0;
        for(int i=0;i<k;i++){
            ans+=arr[i];
        }
        int curr=ans;
        for(int i=k-1;i>=0;i--){
            curr-=arr[i];
            curr+=arr[n+i-k];
            ans= max(ans, curr);
        }
        return ans;
    }
};
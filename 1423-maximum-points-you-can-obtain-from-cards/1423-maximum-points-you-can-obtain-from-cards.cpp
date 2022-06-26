class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n =arr.size();
        int left[n+1], right[n+1];
        left[1]=arr[0], right[n-1]= arr[n-1];
        left[0]=0, right[n]= 0;
        for(int i=1;i<n;i++)
            left[i+1]=left[i]+arr[i];
        for(int i= n-2;i>=0;i--)
            right[i]= right[i+1]+arr[i];
        int ans= max(left[k],right[n-k]);
        for(int i=k-1;i>=0;i--)
        {
            // cout<<i<<" "<<n+i-k<<endl;
            ans= max(ans, left[i]+right[n+i-k]);
        }
        return ans;
    }
};
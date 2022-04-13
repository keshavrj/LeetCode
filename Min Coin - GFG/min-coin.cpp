// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int dp[101][10002];
	int MinCoin(vector<int>arr, int amount)
	{
	    int inf= INT_MAX-1;
	    vector<int> dp(amount+1,inf);
	    dp[0]=0;
	    for(int i=1;i<=amount;i++)
	    {
	        for(int j=0;j<arr.size();j++)
	            {
	                if(arr[j]<=i)
	                    dp[i]= min(dp[i], dp[i-arr[j]]+1);
	            }
	    }
	    if(dp[amount]==inf)return -1;
	    return dp[amount];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
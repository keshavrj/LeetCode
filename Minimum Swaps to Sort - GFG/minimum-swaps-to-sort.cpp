// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	void swapp(vector<int> &arr, int i, int j)
	{
	    int temp= arr[i];
	    arr[i]= arr[j];
	    arr[j]= temp;
	}
	int minSwaps(vector<int>&nums)
	{
	    vector<int> temp= nums;
	    sort(temp.begin(), temp.end());
	    map<int, int> mp;
	    for(int i=0;i<nums.size();i++)
	        mp[nums[i]]=i;
	    int ans=0;
	    for(int i=0;i<nums.size();i++)
	   {
	       if(nums[i]!=temp[i]){
	           ans++;
	           int x= nums[i];
	           swapp(nums, i, mp[temp[i]]);
	           mp[x]=mp[temp[i]];
	           mp[temp[i]]=i;
	           
	       }
	   }
	   return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
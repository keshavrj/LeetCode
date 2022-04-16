// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int maxChainLen(struct val arr[],int n)
{
    sort(arr, arr+n ,[](val &a, val &b){
        return a.first<b.first;
    });                        
    vector<int> dp;
    dp.push_back(arr[0].second);
    
    for(int i=1;i<n;i++)
    {
        if(arr[i].first>dp.back())
            dp.push_back(arr[i].second);
        else{
            int index= lower_bound(dp.begin(), dp.end(), arr[i].second)-dp.begin();
            dp[index]= arr[i].second;
        }
    }
    return dp.size();
    
}
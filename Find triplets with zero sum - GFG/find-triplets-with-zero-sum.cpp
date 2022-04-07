// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

 // } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool solve(int arr[],int i, int j, int k)
    {
        if(j>=k)return false;
        
        if(arr[i]+arr[j]+arr[k]==0)return true;
        return solve(arr, i, j+1, k) || solve(arr, i, j, k-1);
    }
    bool findTriplets(int arr[], int n)
    { 
        sort(arr, arr+n);
        for(int i=0;i<n-1;i++)
        {
            int l= i+1, h= n-1;
            while(l<h){
                int sm= arr[i]+arr[l]+arr[h];
                if(sm==0)return true;
                if(sm>0)h--;
                else l++;
            }
            
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}  // } Driver Code Ends
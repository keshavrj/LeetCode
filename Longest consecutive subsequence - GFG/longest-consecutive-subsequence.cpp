// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
    //   unordered_map<int,int> mp;
    //   for(int i:arr)
    //     mp[i]++;
        
    sort(arr,arr+N);
    int res=1, temp=1;
    for(int i=1;i<N;i++)
    {
        if(arr[i]==arr[i-1]+1)
            temp++;
        else if(arr[i]==arr[i-1])continue;
        else temp=1;
        
        res= max(res,temp);
        
    }
      return res;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends
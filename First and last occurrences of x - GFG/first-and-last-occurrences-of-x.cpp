// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
  
int findFirst(int arr[], int n, int x)
{
    int l=0, r= n-1, flag=0;
    while(l<=r)
    {
        
        int mid= l+ (r-l)/2;
        if(arr[mid]==x){flag=1;
            r=mid-1;}
        else if(arr[mid]<x)
            l= mid+1;
        else r= mid-1;
    }
    if(!flag)return -1;
    return l;
}
int findLast(int arr[], int n, int x)
{
    int l=0, r= n-1, flag=0;
    while(l<=r)
    {
        int mid= l+ (r-l)/2;
        if(arr[mid]==x){flag=1;
            l=mid+1;}
        else if(arr[mid]<x)
            l= mid+1;
        else r= mid-1;
    }
    if(!flag)return -1;
    return r;
}
vector<int> find(int arr[], int n , int x )
{
    int a= findFirst(arr, n, x);
    int b= findLast(arr, n, x);
    return {a, b};
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends
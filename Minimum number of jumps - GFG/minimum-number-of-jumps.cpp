// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        if(n<2)return 0;
        if(arr[0]==0)return -1;
        int cnt=1;
        int max_jump=arr[0];
        for(int i=1, steps=arr[0];i<n;i++)
        {
            if(i==n-1)return cnt;
            steps--;
            max_jump= max(max_jump, i+arr[i]);
            if(steps==0)
            {
                cnt++;
                if(i>=max_jump)return -1;
                steps= max_jump-i;
            }
        }
        
        
        return cnt;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
// { Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        int l=0, r= n-1;
        while(l<r)
        {
            int mid= l+ (r-l)/2;
            if(arr[mid]!=arr[mid-1] && arr[mid]!= arr[mid+1])return arr[mid];
            if(mid&1)
            {
                if(arr[mid]==arr[mid-1])
                    l=mid+1;
                else r= mid-1;
            }
            else{
                    if(arr[mid]==arr[mid+1])
                        l=mid+1;
                else r= mid-1;
                
            }
            
            
        }
        return arr[l];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}  // } Driver Code Ends
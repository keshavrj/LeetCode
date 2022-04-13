// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
 #define ll long long int
 class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    ll merge(ll arr[], ll l, ll mid, ll r)
    {
        ll temp[r-l+1], i=l, j=mid+1, k=0, inv=0;
        while(i<=mid && j<=r)
        {
            if(arr[i]<=arr[j])
                temp[k++]= arr[i++];
            else{
                inv+= mid-i+1;
                temp[k++]= arr[j++];
            }
        }
        while(i<=mid)
            temp[k++]=arr[i++];
        while(j<=r)
            temp[k++]=arr[j++];
        for(int i=l, k=0;i<=r;i++, k++)
            arr[i]= temp[k];
        
        return inv;
            
    }
    
    ll solve(ll arr[], ll l, ll r)
    {
        ll inv=0ll, mid;
        if(l<r)
        {
            mid= (l+r)/2;
            inv+= solve(arr, l, mid);
            inv+=solve(arr, mid+1,r);
            inv+=merge(arr, l, mid, r);
        }
        return inv;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return solve(arr, 0, N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
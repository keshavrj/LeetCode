// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int search(int arr[], int l, int h, int key){
        int n= h+1;
        while(l<h)
        {
            int mid= (l+h)/2;
            if(arr[mid]>arr[h])
                l= mid+1;
            else h= mid;
        }
        int rot= l;
        l=0, h= n-1;
        while(l<=h)
        {
            int mid= (l+h)/2;
            int org= (mid+rot)%n;
            if(arr[org]==key)return org;
            if(arr[org]>key)
                h= mid-1;
            else l= mid+1;
        }
        return -1;
        
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends
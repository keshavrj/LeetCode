// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    // code here
    int l=0, r=n-1;
    bool flag=0;
    while(l<=r)
    {
        int mid= l+ (r-l)/2;
        
        if(arr[mid]==1){
            flag=1;
            r= mid-1;
        }
        else l= mid+1;
        
        
    }
    if(flag)return l;
    return -1;
    
}
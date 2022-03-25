// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int* greaterElement(int arr[], int n);

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int *b;
        b = greaterElement(arr, n);
        for(int i=0;i<n;i++){
            if(b[i] == -10000000)
                cout << "_ ";
            else
                cout << b[i] << " ";
        }
        cout<<endl;   
        
    }
    return 0;
}
// } Driver Code Ends

int find_Next(vector<int> &arr, int k)
{
    // if(k==arr.back())return -1;
 int l=0, r=arr.size()-1;
 while(l<=r)
 {
     int mid= l+ (r-l)/2;
     if(arr[mid]<=k)
        l= mid+1;
     else r= mid-1;
 }
 return l==arr.size() ? -1 : l;
    
}
int* greaterElement(int arr[], int n)
{
    int nl= -1e7;
    vector<int> st;
    for(int i=0;i<n;i++)st.push_back(arr[i]);
    sort(st.begin(), st.end());
    for(int i=0;i<n;i++)
    {
        // auto x= st.upper_bound(arr[i]);
        int x= find_Next(st, arr[i]);
        if(x==-1)
            arr[i]= nl;
        else arr[i]= st[x];
    }
    return arr;
   
}

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
	    sort(A,A+n);sort(B,B+m);
	    long long int sumA=accumulate(A,A+n, 0LL), sumB= accumulate(B, B+m, 0ll);
	   
	    for(int i=0, j=0 ;i<n && j<m; )
	    {
	        long long int p= sumA-A[i]+B[j];
	        long long int q= sumB-B[j]+A[i];
	        if(p==q)return 1;
	        
	        else if(p<q)
	            j++;
	       
	        else i++;
	    }
	    return -1;
	}
 

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends
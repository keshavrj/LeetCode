// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	bool isSquare(long double n)
	{
	     long double x= sqrtl(n); 
	       return ceil(x)==floor(x);
	}
	long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p){
	   
	   vector<pair<long long, long long>> vp(N);
	   for(int i=0;i<N;i++)
	        vp[i]= {w[i], p[i]};
	   sort(vp.begin(), vp.end(), [](pair<long long,long long> &a,pair<long long, long long> &b ){
	       return ( (long double)a.second/a.first) > ((long double)b.second/b.first);
	   });
	   long double ans =0;
	   int i;
	   for(i=0;i<N;i++)
	   {
	       //long double x= sqrtl(vp[i].first); 
	       if(isSquare(vp[i].first))continue;
	       if(C>=vp[i].first)
	       {
	           ans+=vp[i].second;
	           C-=vp[i].first;
	       }
	       else{
	           break;
	       }
	   }
	   if(C>0)
	   {
	       long double p= (long double)vp[i].second/vp[i].first;
	       //if(isSquare(p))continu
	       long double x= C*p;
	    ans+=x;
	       
	   }
	   return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends
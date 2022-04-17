// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	bool isValid(int x, int y, int N)
	{
	    return x>=1 && x<=N && y>=1 && y<=N;
	}
	int minStepToReachTarget(vector<int>&st,vector<int>&end,int N)
	{
	    int dx[]={1,1,2, 2, -1,-1, -2, -2};
	    int dy[]={2,-2,1,-1, 2, -2, 1, -1};
	    bool vis[N+1][N+1]={{0}};
	    int  dis[N+1][N+1]={{0}};
	    queue<pair<int,int>> q;
	    q.push({st[0],st[1]});
	    vis[st[0]][st[1]]=1;
	    dis[st[0]][st[1]]=0;
	    while(!q.empty())
	    {
	        auto t= q.front();
	        int x= t.first;
	        int y=t.second;
	        q.pop();
	        for(int i=0;i<8;i++)
	        {
	            if(isValid(x+dx[i],y+dy[i],N) && !vis[x+dx[i]][y+dy[i]])
	               {
	                   vis[x+dx[i]][y+dy[i]]=1;
	                   dis[x+dx[i]][y+dy[i]]=dis[x][y]+1;
	                   q.push({x+dx[i], y+dy[i]});
	               }
	        }
	    }
	    return dis[end[0]][end[1]];
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
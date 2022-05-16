// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > m, int r, int c) 
    {
        vector<int> ans;
        int left= 0, right= c-1, bottom=r-1, top= 0, dir=1, k=0;
        while(k<r*c)
        {
            if(dir==1)
            {
                for(int i=left;i<=right;i++)
                    ans.push_back(m[top][i]), k++;
                top++;
                dir=2;
            }
            else if(dir==2){
                for(int i= top;i<=bottom;i++)
                    ans.push_back(m[i][right]), k++;
                right--;
                dir=3;
            }
            else if(dir==3)
            {
                for(int i=right;i>=left;i--)
                    ans.push_back(m[bottom][i]), k++;
                bottom--;
                dir=4;
            }
            else{
                for(int i=bottom;i>=top;i--)
                    ans.push_back(m[i][left]), k++;
                left++;
                dir=1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
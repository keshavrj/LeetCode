class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m= grid[0].size(), n= grid.size();
        int N= m*n;
        k%=N;
        int x=0;
        vector<int> arr(N), arr2(N);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++, x++)
                arr[x]= grid[i][j];
        
        
        for(int i=0, x=0;i<N;i++, x++)
        {
            if(i<k)
                arr2[x]= arr[N+i-k];
            else arr2[x]= arr[i-k];
        }
        // for(int i:arr2)cout<<i<<" ";
        
        x=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                grid[i][j]= arr2[x++];
        
        return grid;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int k) {
        int row= m.size(), col= m[0].size();
        int l=0, r=row*col-1;
        while(l<=r)
        {
            int mid= l+ (r-l)/2;
            if(m[mid/col][mid%col]==k)return true;
            else if(m[mid/col][mid%col]<k)l= mid+1;
            else r= mid-1;
        }
        return false;
    }
};
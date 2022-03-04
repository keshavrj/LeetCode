class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double t[query_row+4][query_glass+4];
        memset(t, 0, sizeof t);
        t[0][0]= poured;
        for(int i=0;i<=query_row;i++)
        {
            for(int j=0;j<=query_glass;j++)
            {
                double rem= max(t[i][j]-1.0, 0.0);
                t[i+1][j]+= rem/2.0;
                t[i+1][j+1]+= rem/2.0;
            }
        }
        return min(t[query_row][query_glass], 1.0);
    }
};
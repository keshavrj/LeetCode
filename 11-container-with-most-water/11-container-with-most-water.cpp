class Solution {
public:
    int maxArea(vector<int>& h) {
        int l=0, r= h.size()-1, area=0;
        while(l<r)
        {
            int H= min(h[r], h[l]);
            area= max(area, (r-l)*H);
            while(l<r && h[l]<=H)l++;
            while(l<r && h[r]<=H)r--;
            
        }
        return area;
    }
};
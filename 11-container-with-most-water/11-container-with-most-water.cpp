class Solution {
public:
    int maxArea(vector<int>& h) {
        int l=0, r= h.size()-1, area=0;
        while(l<r)
        {
            area= max(area, (r-l)*(min(h[r], h[l])));
            if(h[r]<h[l])r--;
            else if(h[r]>h[l])l++;
            else l++, r--;
        }
        return area;
    }
};
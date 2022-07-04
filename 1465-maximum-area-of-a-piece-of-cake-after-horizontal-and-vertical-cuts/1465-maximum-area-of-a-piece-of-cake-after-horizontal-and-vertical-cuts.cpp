class Solution {
public:
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
        sort(hCuts.begin(), hCuts.end());
        sort(vCuts.begin(), vCuts.end());
        int max_h= max(hCuts[0], h-hCuts.back()), max_v= max(vCuts[0], w-vCuts.back());
        for(int i=1;i<hCuts.size();i++){
            max_h= max(max_h, hCuts[i]-hCuts[i-1]);
        }
        for(int i=1;i<vCuts.size();i++){
            max_v= max(max_v, vCuts[i]-vCuts[i-1]);
        }
        return ((long long)max_h*(long long)max_v)%1000000007;
    }
};
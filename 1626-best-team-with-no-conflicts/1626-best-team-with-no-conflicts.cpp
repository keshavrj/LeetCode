class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> vp;
        for(int i=0;i<scores.size();i++)
            vp.push_back({ages[i], scores[i]});
        
        sort(vp.begin(),vp.end());
        int n= vp.size();
        vector<int> d(n, 0);

            for (int i = 0; i < n; i++) {
                d[i]= vp[i].second;
            for (int j = 0; j <i; j++) {
            if (vp[j].second <= vp[i].second )
                d[i] = max(d[i], d[j] + vp[i].second);
            }
        }
                                              
        return *max_element(d.begin(), d.end());
    }
};
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n= scores.size();
        
        vector<pair<int,int>> vp(n);
        vector<int> d(n, 0);
        
        for(int i=0;i<scores.size();i++)
            vp[i]= {ages[i], scores[i]};
        
        sort(vp.begin(),vp.end());
      

        for (int i=0;i<n;i++){
            d[i]= vp[i].second;
            for (int j=0;j<i;j++){
                if (vp[j].second<=vp[i].second)
                    d[i] = max(d[i], d[j] + vp[i].second);
            }
        }
                            
        return *max_element(d.begin(), d.end());
    }
};
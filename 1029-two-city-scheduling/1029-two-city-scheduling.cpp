class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sm=0;
        vector<int> refund;
        for(auto i:costs)
            sm+=i[0], refund.push_back(i[1]-i[0]);
        
        sort(refund.begin(), refund.end());
        for(int i=0;i<costs.size()/2;i++)
            sm+= refund[i];
        
        return sm;
        
    }
};
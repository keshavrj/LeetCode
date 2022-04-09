class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        
        unordered_map<int,int > mp;
        for(int i:nums)mp[i]++;
        
        for(auto i= mp.begin();i!=mp.end();i++)
        {
            pq.push({i->second, i->first});
            if(pq.size()>(int)mp.size()-k)
            {
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};
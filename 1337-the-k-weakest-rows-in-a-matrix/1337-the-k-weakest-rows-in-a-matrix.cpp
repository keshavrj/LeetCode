class Solution {
public:
    int count1(vector<int> &a)
    {
        int cnt=0;
        for(int i:a)
        {
            if(i==1)
                cnt++;
            else break;
        }
        return cnt;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n= mat.size();
        vector<pair<int, int>> mp;
        for(int i=0;i<mat.size();i++)
        {
            mp.push_back({i,count1(mat[i])});
        }
        sort(mp.begin(), mp.end(), [](const pair<int,int> &a, const pair<int,int> &b)
             {
                if(a.second==b.second)return a.first<b.first;
                 return a.second<b.second;
             });
        vector<int> ans;
        for(auto i= mp.begin();i!=mp.end() && k; i++, k--)
        {
            ans.push_back(i->first);
        }
        return ans;
    }
};
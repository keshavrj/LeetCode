class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& arr, string word)     {
        sort(arr.begin(), arr.end());
        vector<vector<string>> ans;
         // for(int i=0;i<word.size();i++)
         // {
         //    vector<string> res;
         //    string s= word.substr(0,i+1);
         //    int cnt=0;
         //     for(int j=0;j<arr.size() && cnt<3;j++)
         //    {
         //        string t= arr[j].substr(0,i+1);
         //        if(t==s)
         //        {
         //            res.push_back(arr[j]);
         //            cnt++;
         //        }
         //    }
         //     ans.push_back(res);
         // }
        auto startIndex= arr.begin();
        string prefix="";
        int n= arr.size();
        for(auto &c:word){
            prefix+=c;
            startIndex= lower_bound(arr.begin(), arr.end(), prefix);
            vector<string> t;
            int ind= startIndex-arr.begin();
            for(int i=ind;i<min(ind+3, n);i++)
            {
                if(arr[i].find(prefix)!=-1)
                    t.push_back(arr[i]);
            }
            ans.push_back(t);
        }
    return ans;
    }
};
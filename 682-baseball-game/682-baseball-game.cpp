class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>  v;
        for(auto i:ops)
        {
            if(i=="C")
                v.pop_back();
            else if(i=="D")
            {
                // if(!v.empty())v.push_back(v.back()*2);
                // else 
                //     v.push_back(a.back()*2);
                v.push_back(v.back()*2);
            }
            else if(i=="+"){
                int sz= v.size();
                v.push_back(v[sz-1]+v[sz-2]);
            }
            else{
                v.push_back(stoi(i));
                // a.push_back(v.back());
            }
            
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};
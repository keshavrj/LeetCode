class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        for(auto w:st){
            for(int i=1;i<w.size();i++)
                st.erase(w.substr(i));
        }
        int res=0;
        for(auto i:st)
            res+=1+i.size();
        return res;
    }
};
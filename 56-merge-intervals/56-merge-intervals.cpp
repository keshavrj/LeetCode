class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int first_el=arr[0][0];
        int second_el=arr[0][1]; 
        int i=1;
        ans.push_back({first_el, second_el});
        while(i<arr.size())
        {
            if(ans.back()[1]>=arr[i][0])
                ans.back()[1]= max(ans.back()[1], arr[i][1]);
            else ans.push_back(arr[i]);
            i++;
        }
        // ans.back()[1]= arr[arr.size()-1][1];
        
        
        
        return ans;
    }
};
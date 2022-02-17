/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    unordered_map<int, int> mp;
    int max_freq=0;
    int solve(TreeNode* root, int sm)
    {
        if(!root)return 0;
        sm=root->val+solve(root->left, sm)+solve(root->right, sm );
        max_freq= max(max_freq, ++mp[sm]);
        return sm;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int sm=0;
        solve(root, sm);
        for(auto i:mp)
            if(i.second==max_freq)
                ans.push_back(i.first);
        
        return ans;
            
    }
};
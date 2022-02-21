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
    map<int,int> mp;
    void solve(TreeNode* root)
    {
        if(!root)return;
        solve(root->left);
        mp[root->val]++;
        solve(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        int mx=-1;
        vector<int> ans;
        solve(root);
        for(auto i:mp)
            mx=max(mx,i.second);
        for(auto i:mp)
            if(i.second==mx)
                ans.push_back(i.first);
        
        return ans;
    }
};
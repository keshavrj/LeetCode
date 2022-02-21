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
    int pre_el= INT_MIN, curr_freq=0, max_freq=0;
    void solve(TreeNode* root)
    {
        if(!root)return;
        solve(root->left);
        if(pre_el == root->val)curr_freq++;
        else curr_freq=1;
        if(curr_freq>max_freq)
        {
            ans.clear();
            max_freq= curr_freq;
            ans.push_back(root->val);
        }
        else if(curr_freq==max_freq)
            ans.push_back(root->val);
        
        pre_el= root->val;
        solve(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        solve(root);
        return ans;
    }
};
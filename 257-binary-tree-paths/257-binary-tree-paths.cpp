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
    vector<string> ans;
    void solve(TreeNode* root, string t){
        if(!root->left && !root->right)
        {
            ans.push_back(t);
            return;
        }
        if(root->left)
            solve(root->left, t+"->"+to_string(root->left->val));
        if(root->right)
            solve(root->right, t+"->"+to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)return ans;
        solve(root,to_string(root->val) );
        return ans;
    }
};
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
    bool solve(TreeNode* root, int k)
    {
        if(!root)return true;
        if(root->val!=k)
            return false;
        return solve(root->left, k) && solve(root->right, k);
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root)return true;
        int k=root->val;
        return solve(root, k);
    }
};
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
    int solve(TreeNode* root, int target)
    {
        if(!root)return 0;
        if(target==root->val)
            return 1+solve(root->left, target-root->val) + solve(root->right, target-root->val);
        return solve(root->left, target-root->val) + solve(root->right, target-root->val);
    }
    int pathSum(TreeNode* root, int target) {
        if(!root)return 0;
        return solve(root, target)+pathSum(root->left, target)+pathSum(root->right, target);
    }
};
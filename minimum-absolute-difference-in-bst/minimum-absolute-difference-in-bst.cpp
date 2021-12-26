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
    int prev_val=-1, mn= INT_MAX;
    int getMinimumDifference(TreeNode* root) {
    if(!root)
            return mn;
        getMinimumDifference(root->left);
        if(prev_val>=0)
            mn= min(mn, abs(root->val - prev_val));
        prev_val = root->val;
        getMinimumDifference(root->right);
        return mn;
    }
};
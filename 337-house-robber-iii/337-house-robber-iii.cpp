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
    unordered_map<TreeNode*, int> mp;
//     int solve(TreeNode* root)
//     {
        
//     }
    int rob(TreeNode* root) {
        if(!root)return 0;
        if(mp[root])return mp[root];
        //if we include the current Node 
        int val= root->val;
        if(root->left)
            val+= rob(root->left->left) + rob(root->left->right);
        if(root->right)
            val+= rob(root->right->left)+ rob(root->right->right);
        int excl= rob(root->left)+rob(root->right);
        val= max(val, excl);
        return mp[root]= val;
    }
};
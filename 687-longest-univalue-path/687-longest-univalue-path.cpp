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
    int res=INT_MIN;
    int solve(TreeNode* root, int val)
    {
        if(!root)return 0;
        
        int l= solve(root->left, root->val);
        int r= solve(root->right, root->val);
        res= max(res, l+r);
        if(val==root->val)return 1+max(l,r);
        return 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        res=0;
        if(root)solve(root, root->val);
        return res;
    }
};
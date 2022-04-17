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
    void inorder(TreeNode *root, TreeNode* &t)
    {
        if(!root)return;
        inorder(root->left, t);
        t->right= new TreeNode(root->val);
        t=t->right;
        inorder(root->right,t);
    }
    TreeNode* increasingBST(TreeNode* root) {
        
        TreeNode *ans, *t=new TreeNode();
        ans=t;
        inorder(root,t);
        return ans->right;
        
    }
};
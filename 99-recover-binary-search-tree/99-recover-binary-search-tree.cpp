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
    TreeNode *first=NULL, *second=NULL, *prev= NULL;
    void Inorder(TreeNode* root)
    {
        if(!root)return;
        Inorder(root->left);
        if(prev == NULL) prev = root;
        else {
            if(first==NULL && prev->val >= root->val)   first=prev;
            if(first!=NULL && prev->val >= root->val)   second=root;
        
        
        prev=root;
        }
        Inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        
        Inorder(root);
        swap(first->val,second->val);
    }
};
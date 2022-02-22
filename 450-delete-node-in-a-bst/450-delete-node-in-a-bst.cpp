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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
        if(root->val>key)root->left= deleteNode(root->left, key);
        else if(root->val<key)root->right= deleteNode(root->right, key);
        else{
        //case I;
        if(!root->left && !root->right)return NULL;
        //case II && Case III:
        if(!root->left || !root->right)
            return root->left!=NULL ? root->left : root->right;
        // case IV:
        auto succ= root->right;
        while(succ->left)
            succ=succ->left;
        root->val= succ->val;
        root->right = deleteNode(root->right,succ->val);
            
        }
       return root;
        
    }
};
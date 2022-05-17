/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(target==original)return cloned;
        if(original==NULL)return NULL;
        TreeNode* l= getTargetCopy(original->left, cloned->left, target);
        TreeNode* r= getTargetCopy(original->right, cloned->right, target);
        return l==NULL ? r : l;
    }
};
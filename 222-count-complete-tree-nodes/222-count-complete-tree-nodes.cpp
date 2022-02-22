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
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int lDepth=0, rDepth=0;
        for(auto p=root;p;p=p->left)lDepth++;
        for(auto p=root;p;p=p->right)rDepth++;
        if(lDepth==rDepth)return (1<<lDepth)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
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
     vector<TreeNode*> nodes;
    void find(TreeNode* root, TreeNode* subRoot){
        if(!root )return;
        if(subRoot->val==root->val)
            nodes.push_back(root);
        find(root->left, subRoot);
        find(root->right, subRoot);
    }
    bool solve(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot)return true;
        if(!root || !subRoot)return false;
        if(root->val!=subRoot->val)return false;
        return solve(root->left, subRoot->left) && solve(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)return false;
        if(solve(root, subRoot))return true;
          return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
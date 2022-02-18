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
    int solve(TreeNode* root, int &x)
    {
        if(!root)return -1;
        if(root->val!=x)return root->val;
        
        int l= solve(root->left, x), r=  solve(root->right, x);
        if(l==-1)return r;
        if(r==-1)return l;
        return min(l,r);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)return -1;
        int x= root->val;
        return solve(root, x);
    }
};
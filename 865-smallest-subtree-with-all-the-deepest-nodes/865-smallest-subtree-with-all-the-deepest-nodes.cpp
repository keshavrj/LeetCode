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
    pair<int, TreeNode*> solve(TreeNode* root)
    {
        if(!root)return {0,NULL};
        auto l= solve(root->left);
        auto r= solve(root->right);
        int d1= l.first, d2= r.first;
        if(d1==d2)return {d1+1, root}; //or {d2+1, root};
        if(d1>d2) 
            return {d1+1, l.second};
        return  {d2+1, r.second};
        
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).second;
    }
};
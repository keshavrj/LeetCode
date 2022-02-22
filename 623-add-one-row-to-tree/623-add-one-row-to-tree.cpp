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
    void solve(TreeNode* root, int val, int d, int h)
    {
        if(h==d-1)
        {
            auto l= new TreeNode(val, root->left, NULL);
            auto r= new TreeNode(val, NULL, root->right);
            root->left= l;
            root->right= r;
            return;
        }
        solve(root->left, val, d, h+1);
        solve(root->right, val, d, h+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root)return NULL;
        if(depth==1)
        {
            auto t= new TreeNode(val, root, NULL);
            return t;
        }
        if(depth==2)
        {
            root->left= new TreeNode(val, root->left, NULL);
            root->right= new TreeNode(val, NULL, root->right);
            return root;
        }
        addOneRow(root->left, val, depth-1);
        addOneRow(root->right, val, depth-1);
        return root;
    }
};
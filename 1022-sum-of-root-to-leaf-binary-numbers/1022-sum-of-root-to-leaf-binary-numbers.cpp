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
    int ans=0;
    void solve(TreeNode* root, int x)
    {
        if(!root->left && !root->right)
        {
            // cout<<x<<endl;
            ans+=x;
            return;
        }
        if(root->left)
            solve(root->left, (x<<1)|(root->left->val));
        if(root->right)
            solve(root->right, (x<<1)|(root->right->val));
        
    }
    int sumRootToLeaf(TreeNode* root) {
        if(!root)return 0;
        solve(root, root->val);
        return ans;
    }
};
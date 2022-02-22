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
    int h, ans;
    bool flag=0;
    int height(TreeNode* root){
        if(!root)return 0;
        return 1+ max(height(root->left), height(root->right));
    }
    void solve(TreeNode* root, int h)
    {
        if(!root)return;
        if(h==1){
            flag=1;
            ans= root->val;
            return;
        }
        solve(root->left, h-1);
        if(!flag)
        solve(root->right, h-1);
        // return root->val;
    }
    int findBottomLeftValue(TreeNode* root) {
        h=height(root);
        // cout<<h;
        solve(root, h);
        return ans;
    }
};
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
    int ans;
    // int h, ans;
    // bool flag=0;
    // int height(TreeNode* root){
    //     if(!root)return 0;
    //     return 1+ max(height(root->left), height(root->right));
    // }
    // void solve(TreeNode* root, int h)
    // {
    //     if(!root)return;
    //     if(h==1){
    //         flag=1;
    //         ans= root->val;
    //         return;
    //     }
    //     solve(root->left, h-1);
    //     if(!flag)
    //     solve(root->right, h-1);
    //     // return root->val;
    // }
    void solve(TreeNode* root, int Depth, int &height)
    {
        if(!root)return;
        if(Depth>height)
        {
            ans= root->val;
            height= Depth;
        }
        solve(root->left, Depth+1, height);
        solve(root->right, Depth+1, height);
    }
    int findBottomLeftValue(TreeNode* root) {
        // h=height(root);
        // // cout<<h;
        // solve(root, h);
        // return ans;
        int h= 0;
        solve(root, 1, h);
        return ans;
    }
};
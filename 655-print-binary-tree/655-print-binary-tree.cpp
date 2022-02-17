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
    int h;
    int height(TreeNode* root)
    {
        if(!root)return 0;
        int l= height(root->left);
        int r= height(root->right);
        return 1+max(l,r);
    }
    void solve(vector<vector<string>> &ans, TreeNode *root, int level , int l, int r)
    {
        if(!root)return;
        int mid= l+(r-l)/2;
        ans[level][mid]= to_string(root->val);
        solve(ans, root->left,level+1, l, mid-1);
        solve(ans, root->right,level+1, mid+1, r);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        h= height(root);
        cout<<h;
        int m= h;
        int n= (1<<m) - 1;
        vector<vector<string>> ans(m,vector<string> (n, ""));
        int l=0, r= n-1;
        int mid= l+(r-l)/2;
        int level=0;
        ans[level][mid]=to_string(root->val);
        solve(ans, root->left, level+1, l, mid-1);
        solve(ans, root->right, level+1, mid+1, r);
        return ans;
    }
};
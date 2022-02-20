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
    vector<int> v1,v2;
    void solve(TreeNode* root)
    {
        if(!root)return;
        solve(root->left);
        solve(root->right);
        if(!root->left && !root->right)
            v2.push_back(root->val);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        solve(root1);
        swap(v1,v2);
        solve(root2);
        if(v1.size()!=v2.size())return false;
        for(int i=0;i<v1.size();i++ )
            if(v1[i]!=v2[i])
                return false;
        return true;
    }
};
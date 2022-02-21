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
    // void solve(TreeNode* root, vector<int> &v)
    // {
    //         if(!root)return;
    //         solve(root->left, v);
    //         v.push_back(root->val);
    //         solve(root->right, v);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
    vector<int> v;
    auto curr=root;
    while(curr)
    {
        if(!curr->left)
        {
            v.push_back(curr->val);
            curr=curr->right;
        }
        else{
            auto pre= curr->left;
            while(pre->right && pre->right!=curr)
                pre= pre->right;
            
            if(pre->right==NULL)
            {
                pre->right= curr;
                curr= curr->left;
            }
            else{
                pre->right=NULL;
                v.push_back(curr->val);
                curr= curr->right;
            }
        }
    }
    return v;
    
    }
};
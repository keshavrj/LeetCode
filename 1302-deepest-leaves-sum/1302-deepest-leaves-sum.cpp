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
    int height(TreeNode* root)
    {
        if(!root)return 0;
        return 1+max(height(root->left), height(root->right));
    }
    int deepestLeavesSum(TreeNode* root) {
        if(!root)return 0;
        int h= height(root);
        queue<TreeNode*> q;
        q.push(root);
        int level=1, ans=0;
        while(!q.empty())
        {
            int sz= q.size();
            for(int i=0;i<sz;i++)
            {
                auto t= q.front();
                q.pop();
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
                if(level==h)ans+=t->val;
            }
            level++;
        }
        return ans;
    }
};
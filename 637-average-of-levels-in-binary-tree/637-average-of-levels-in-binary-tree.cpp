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

    vector<double> averageOfLevels(TreeNode* root) {
            vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz= q.size();
            double sm=0.0;
            for(int i=0;i<sz;i++)
            {
                auto t= q.front();q.pop();
                sm+=t->val;
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            ans.push_back(sm/sz);
        }
        return ans;
    }
};
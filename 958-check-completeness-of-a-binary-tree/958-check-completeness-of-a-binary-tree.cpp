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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;q.push(root);
        vector<TreeNode*> v;
        v.push_back(root);
        while(!q.empty())
        {
            auto t= q.front();q.pop();
            while(t==NULL && !q.empty())
                t=q.front(), q.pop();
            if(t){
            q.push(t->left);
            q.push(t->right);
            // v.push_back(t);
            v.push_back(t->left);
            v.push_back(t->right);
            }
        }
        while(v.back()==NULL)
           v.pop_back();
        for(auto i:v)
            if(!i)return false;
        return true;
    }
};
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(!root)return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto p= q.front();q.pop();
            v.push_back(p->val);
            int sz=q.size();
            if(p->right)q.push(p->right);
            if(p->left)q.push(p->left);
            for(int i=0;i<sz;i++){
                auto x= q.front();
                q.pop();
                if(x->right)q.push(x->right);
                if(x->left)q.push(x->left);
            }
        }
        return v;
    }
};
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
    void dfs(TreeNode* root, vector<vector<int>>& res, int level){
        if(!root)return;
        if(level==res.size())res.push_back(vector<int> ());
        res[level].push_back(root->val);
        dfs(root->left,res,level+1);
        dfs(root->right,res,level+1);
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        dfs(root, ans, 0);
        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty()){
        //     int n=q.size();
        //     vector<int> v;
        //     for(int i=0;i<n;i++){
        //         auto t=q.front();
        //         v.push_back(t->val);
        //         q.pop();
        //         if(t->left)q.push(t->left);
        //         if(t->right)q.push(t->right);
        //     }
        //     ans.push_back(v);
        // }
        return ans;
    }
};
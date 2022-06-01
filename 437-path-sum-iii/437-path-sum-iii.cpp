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
    int ans=0;
    void solve(TreeNode* root, int target, vector<int> &path){
        if(!root)return;
        path.push_back(root->val);
        solve(root->left, target, path);
        solve(root->right, target, path);
        long long int x= 0;
        for(int i= path.size()-1;i>=0;i--){
            x+=(long long)path[i];
            if(x==target)ans++;
        }
        
        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        solve(root, targetSum, path);
        return ans;
    }
};
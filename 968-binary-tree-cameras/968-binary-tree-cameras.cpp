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
    // inspired from discuss;
    int HAS_CAMERA=1, NO_CAMERA=0, NOT_NEEDED=2, ans=0;
    int dfs(TreeNode* root){
        if(!root)return NOT_NEEDED;
        int l= dfs(root->left), r= dfs(root->right);
        if(l==NO_CAMERA || r==NO_CAMERA){
            ans++;
            return HAS_CAMERA;
        }
        else if(l==HAS_CAMERA || r==HAS_CAMERA)
            return NOT_NEEDED;
        else return NO_CAMERA;
    }
    int minCameraCover(TreeNode* root) {
        if(dfs(root)==NO_CAMERA)ans++;
        return ans;
    }
};
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
    void Inorder_(TreeNode* root, int &val, int &k){
        if(!root || k<=0)
            return;
        Inorder_(root->left, val, k);
        --k;if(k==0){val= root->val;return;}
        Inorder_(root->right,val, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int val=-1;
        Inorder_(root,val,k);
        return val;
    }
};
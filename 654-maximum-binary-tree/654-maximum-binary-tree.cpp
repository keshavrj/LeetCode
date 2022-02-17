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
    TreeNode* solve(vector<int> &nums, int l, int r){
        if(l<0 || r>=nums.size() || l>r)return NULL;
        int mid= max_element(nums.begin()+l, nums.begin()+r+1)-                                 nums.begin();
        TreeNode *node= new TreeNode(nums[mid]);
        node->left= solve(nums, l, mid-1);
        node->right= solve(nums, mid+1, r);
        
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n= nums.size();
        return solve(nums, 0, n-1);
    }
};
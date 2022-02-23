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
class CBTInserter {
public:
    TreeNode* head;
    CBTInserter(TreeNode* root) {
        head= root;
    }
    
    int insert(int val) {
        queue<TreeNode*> q;q.push(head);
        while(!q.empty())
        {
            auto t= q.front();q.pop();
            if(t->left)
                q.push(t->left);
            else{
                t->left= new TreeNode(val);
                return t->val;
            }
            if(t->right)
                q.push(t->right);
            else{
                t->right= new TreeNode(val);
                return t->val;
            }
            
        }
        return 0;
    }
    
    TreeNode* get_root() {
        return head;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
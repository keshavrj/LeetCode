/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode* > parent;
        queue<TreeNode*> q;
        bool vis[502]={0};
        q.push(root);

        parent[root]= NULL;
        while(!q.empty())
        {
            auto curr= q.front();q.pop();
            if(curr->left)
            {
                parent[curr->left]=curr;
                q.push(curr->left);
            }
             if(curr->right)
            {
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
        int dis=0;
        q.push(target);
        vis[target->val]=1;
        while(!q.empty())
        {
            int size= q.size();
            if(dis++==k)break;
            for(int i=0;i<size;i++)
            {
                auto x= q.front();q.pop();
                if(x->left && vis[x->left->val]==0)
                {
                    vis[x->left->val]=1;
                    q.push(x->left);
                    
                }
                if(x->right && vis[x->right->val]==0)
                {
                    vis[x->right->val]=1;
                    q.push(x->right);
                    
                }
                if(parent[x] && vis[parent[x]->val]==0)
                {
                    vis[parent[x]->val]=1;
                    q.push(parent[x]);
                }
            }
          
        }
          vector<int> ans;
            while(!q.empty())
            {
                int x= q.front()->val;q.pop();
                ans.push_back(x);
            }
            return ans;
    }
};
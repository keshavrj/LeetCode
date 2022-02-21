/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return NULL;
        queue<Node*> q;
        q.push(root);
        Node *t;
        while(!q.empty())
        {
            for(int i=size(q)-1;i>0;i--)
            {
                t= q.front();q.pop();
                t->next= q.front();
                if(t->left)q.push(t->left), q.push(t->right);
            }
                t= q.front();q.pop();
                t->next=NULL;
                if(t->left)q.push(t->left), q.push(t->right);
            
        }
        return root;
    }
};
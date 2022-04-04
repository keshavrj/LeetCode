/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p=head, *ff=head, *ss=head;
        for(int i=1;i<k;i++)
            p=p->next;
        ff= p;
        while(p->next)
        {
            p=p->next;
            ss=ss->next;
        }
        swap(ff->val,ss->val);
        return head;
    }
};
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next)return head;
        
        ListNode* p= new ListNode(0, head), *q=head, *start= p->next;
        // p->next=head;
        while(q)
        {
            bool flag=0;
            while(q->next && q->next->val==q->val)
            {
                q=q->next;
                flag=1;
            }
            if(!flag)q=q->next, p=p->next;
            else{
                bool fg=0;
                if(p->next==head)
                    fg=1;
                p->next=q->next;
                q->next=NULL;
                q=p->next;
                if(fg)head=p->next;
            }
            
        }
        return head;
    }
};
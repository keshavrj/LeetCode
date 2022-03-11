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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next)return head;
        int n=1;
        auto p= head;
        while(p->next)
            n++, p=p->next;
        k= k%n;
        n= n-k;
            if(k==0)return head;
            else p->next=head;
        p=head;
        while(n-->1)
        {
            p=p->next;
        }
        head= p->next;
        p->next= NULL;
        return head;
    }
};
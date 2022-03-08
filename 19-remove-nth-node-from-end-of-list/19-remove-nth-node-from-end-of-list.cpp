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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        auto p= head;
        while(p)len++, p=p->next;
        n= len-n+1;
        if(n==1)return head->next;
        p= head;
        int cnt=1;
        while(p && cnt<n)
        {
            if(cnt==n-1)
            {
                // auto q= p->next;
                p->next=p->next->next;
                // q->next=NULL;
                // delete(q);
                return head;
            }
            cnt++;
            p=p->next;
            
        }
        return NULL;
    }
};
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
        
        ListNode *start= new ListNode(0, head);
        ListNode *slow= start, *fast= start;
        for(int i=1;i<=n+1;i++)
            fast= fast->next;
        while(fast)
        {
            fast= fast->next;
            slow= slow->next;
        }
        slow->next=slow->next->next;
        return start->next;
        
//         int len=0;
//         auto p= head;
//         while(p)len++, p=p->next;
//         n= len-n+1;
//         if(n==1)return head->next;
//         p= head;
//         int cnt=1;
//         while(p && cnt<n)
//         {
//             if(cnt==n-1)
//             {
//                 // auto q= p->next;
//                 p->next=p->next->next;
//                 // q->next=NULL;
//                 // delete(q);
//                 return head;
//             }
//             cnt++;
//             p=p->next;
            
//         }
//         return NULL;
    }
};
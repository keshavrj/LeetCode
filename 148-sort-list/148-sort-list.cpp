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
    void mergesort(ListNode **head)
    {
        ListNode* curr= *head;
        ListNode *first, *second;
        if(!curr || !curr->next)return;
        
        findMiddle(curr, &first, &second);
        mergesort(&first);mergesort(&second);
        *head = merge(first, second);
    }
    void findMiddle(ListNode *curr, ListNode **first, ListNode** second)
    {
        
        auto slow= curr;
        auto fast= curr->next;
        while(fast!=NULL)
        {
            fast= fast->next;
            if(fast){
                fast= fast->next;
                slow= slow->next;
            }
        }
        *first= curr;
        *second= slow->next;
        slow->next= NULL;
        
    }
    ListNode* merge(ListNode *first, ListNode *second)
    {
        ListNode *ans=NULL;
        if(!first)return second;
        if(!second)return first;
        if(first->val<=second->val)
        {
            ans= first;
            ans->next=merge(first->next, second); 
        }
        else
        {
            ans= second;
            ans->next=merge(first, second->next); 
        }
        return ans;
    }
    ListNode* sortList(ListNode* head) {
        mergesort(&head);
        return head;
    }
};
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *ans= new ListNode();
        auto head= ans;
        while(l1 or l2)
        {
            int x= (l1?l1->val:0)+ (l2?l2->val:0) +carry;
            ans->next= new ListNode(x%10);
            carry= x/10;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
            ans=ans->next;
        }
        if(carry!=0)
            ans->next= new ListNode(carry);
        return head->next;
    }
};
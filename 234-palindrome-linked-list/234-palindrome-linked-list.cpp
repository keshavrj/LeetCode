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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre= NULL, *ahead=NULL;
        while(head)
        {
            ahead=head->next;
            head->next= pre;
            pre= head;
            head= ahead;
        }
        return pre;
        
    }
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next)return true;
        ListNode *fast= head;
        ListNode *slow= head;
        while(fast->next && fast->next->next)
            slow= slow->next, fast= fast->next->next;
        slow->next= reverseList(slow->next);
        slow= slow->next;
        while(slow)
        {
            if(slow->val!=head->val)return 0;
            slow=slow->next;
            head= head->next;
        }
        return 1;
    }
};
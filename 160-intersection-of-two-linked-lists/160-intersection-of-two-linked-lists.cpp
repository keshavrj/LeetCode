/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=0, m=0;
        auto p= headA, q= headB;
        while(headA)
            n++, headA=headA->next;
        while(headB)
            m++, headB=headB->next;
        
        headA=p;
        headB=q;
        // cout<<n<<" "<<m<<endl;
        while(n>m && headA)
            n--, headA=headA->next;
        while(m>n && headB)
            m--, headB=headB->next;
        while(headA && headB)
        {
            if(headA==headB)
                return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
        
    }
};
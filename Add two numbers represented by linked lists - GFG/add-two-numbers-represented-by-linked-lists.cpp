// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverseLL(Node* head)
    {
        Node* prev= NULL;
        while(head)
        {
            Node* temp= head->next;
            head->next= prev;
            prev= head;
            head= temp;
        }
        return prev;
        
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first= reverseLL(first);
        second= reverseLL(second);
        Node* third= NULL, *q;
        int carry=0;
        while(first or second)
        {
            int val=0;
            if(first && second)
                val= first->data + second->data + carry;
            else val= (first==NULL ? (second->data+carry) : (first->data+carry));
            
            Node* t = new Node(val%10);
            carry= val/10;
            
            if(!third) {third=t;q=t;}
            else {q->next= t; q=q->next;}
            if(first)
                first= first->next;
            if(second)
                second= second->next;
            
        }
        if(carry!=0)
            q->next= new Node(carry);
        third= reverseLL(third);
        return third;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends
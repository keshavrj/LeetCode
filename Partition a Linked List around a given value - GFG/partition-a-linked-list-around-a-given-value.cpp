// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
struct Node* partition(struct Node* head, int x){
    
    Node *h1=NULL,*l1=NULL, *h2=NULL, *l2=NULL, *h3=NULL,*l3=NULL;
    while(head)
    {
        if(head->data<x)
            h1 ? l1 = l1->next=head : l1=h1=head;  
        else if(head->data==x)
            h2 ? l2 = l2->next=head : l2=h2=head;  
        else
            h3 ? l3 = l3->next=head : l3=h3=head;
        head=head->next;
    }
    // auto *p=h2;
    // while(p)
    // {
    //     cout<<p->data<<" ";
    //     p=p->next;
    // }
    // cout<<endl;
    if(l3)
        l3->next=NULL;
    if(l2)
        l2->next=h3;
    else if(l1)
        l1->next=h3;
    
    if(l1 && l2)
        l1->next=h2;
    return h1 ? h1 : h2 ? h2 : h3;
    
    
}
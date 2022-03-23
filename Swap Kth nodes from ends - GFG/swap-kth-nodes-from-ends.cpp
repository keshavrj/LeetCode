// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
void swapNode(Node* preva, Node* a, Node* prevb, Node* b) {
     if(a == prevb) {
         preva->next = b;
         a->next = b->next;
         b->next = a;
     } else if(b == preva) {
         prevb->next = a;
         b->next = a->next;
         a->next = b;
         
     } 
     else {
         Node* aNext = a->next;
         preva->next = b;
         prevb->next = a;
         
         a->next = b->next;
         b->next = aNext;
     }
 }
Node *swapkthnode(Node* head, int num, int k)
{
    
  if(k>num)return head;
  Node* dummy= new Node(-1);
  dummy->next=head;
    Node* first, *second=dummy, *curr=head, *p1=dummy, *p2=dummy;
    second->next= head;
  
  for(int i=1;i<k && curr ;i++)
  {
    p1=curr;
    curr= curr->next;    
  }
  first= curr;
  while(curr)
  {
      p2=second;
      curr=curr->next;
      second = second->next;
  }
  
  swapNode(p1, first, p2, second);
  
  
  return dummy->next;
}

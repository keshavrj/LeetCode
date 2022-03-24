// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverseLL(Node* root)
    {
        Node* curr= root, *prev= NULL;
        while(curr)
        {
            Node* temp=curr->next;
            curr->next= prev;
            prev= curr;
            curr= temp;
        }
        
        return prev;
    }
    bool isPalindrome(Node *head)
    {
    
        Node* fast= head , *slow= head;
        while(fast && fast->next)
        {
            fast= fast->next->next;
            slow= slow->next;
        }
        slow= reverseLL(slow);
        fast= head;
        while(slow)
        {
            if(slow->data!= fast->data)return false;
            slow= slow->next;
            fast=fast->next;
        }
        
        return true;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends
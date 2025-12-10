#include<bits/stdc++.h>
using namespace std;

class Node{

public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }

};

void insertAtHead(Node* &head, int d){

    if(head == NULL){
        head = new Node(d);
        return;
    }

    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &head, int d){

    if(head == NULL){
        head = new Node(d);
        return;
    }

    Node* tail = head;

    while(tail->next != NULL){
        tail = tail->next;
    }

    tail->next = new Node(d);

}

int lengthOfList(Node* head){

    int cnt = 0;
    while(head != NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}

void insertAtMiddle(Node* &head, int data, int position){

    ///Corner Case

    if(head == NULL || position == 0){
        insertAtHead(head,data);
    }
    else if(position > lengthOfList(head)){
        insertAtTail(head,data);
    }
    else{
        int jump = 1;
        Node* temp = head;

        while(jump <= position-1){
            temp = temp->next;
            jump++;
        }

        Node* n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }
}

void deleteAtHead(Node*&head){

    if(head == NULL){
        return;
    }

    Node* temp = head->next;
    delete head;
    head = temp;

}

bool searchRecursive(Node* head, int key){

    if(head == NULL){
        return false;
    }

    if(head->data == key){
        return true;
    }
    else{
        return searchRecursive(head->next,key);
    }

}


void printList(Node* head){

    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}

/// operator overloading

void operator<<(ostream &os, Node* head){
    printList(head);
    return;
}

void reverseLinkedList(Node* &head){

    if(head == NULL){
        return;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* ahead = NULL;

    while(curr != NULL){
        /// save the next node
        Node* ahead = curr->next;
        /// point the current to previous
        curr->next = prev;

        /// update previous and current
        prev = curr;
        curr = ahead;
    }

    head = prev;
}

Node* recursiveReverse(Node* head){   /// O(n^2) approach

    /// Base Case
    if(head->next == NULL || head == NULL){
        return head;
    }

    Node* smallHead = recursiveReverse(head->next);

    Node* temp = smallHead;

    while(temp->next != NULL){
        temp = temp->next;
    }
    head->next = NULL;
    temp->next = head;

    return smallHead;
}

Node* recursiveReverse_2(Node* head){   /// O(n) approach

    /// Base Case
    if(head->next == NULL || head == NULL){
        return head;
    }

    Node* smallHead = recursiveReverse(head->next);

    Node* temp = head->next;
    temp->next = head;
    head->next = NULL;

    return smallHead;
}

Node* merge_sorted_lists(Node* a, Node* b){

    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }

    Node* c;

    if(a->data < b->data){
        c = a;
        c->next = merge_sorted_lists(a->next,b);
    }
    else{
        c = b;
        c->next = merge_sorted_lists(a, b->next);
    }
    return c;
}

int main(){

    Node* head = NULL;

    insertAtHead(head,7);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,1);

    printList(head);

    Node* head2 = NULL;

    insertAtHead(head2,10);
    insertAtHead(head2,8);
    insertAtHead(head2,2);
    insertAtHead(head2,0);

    printList(head2);

    Node* newHead = merge_sorted_lists(head,head2);
    printList(newHead);

   /* insertAtMiddle(head,99,2);
    insertAtTail(head,101);

    printList(head);

    deleteAtHead(head);
    printList(head);

    deleteAtHead(head);
    printList(head);


    reverseLinkedList(head);
    cout<<head;

    Node* head2 = recursiveReverse(head);
    cout<<head2;  */

return 0;
}

#include<bits/stdc++.h>
using namespace std;

class Node{

public:

    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int d){

    if(head == NULL){
        head = new Node(d);
        tail = head;
        return;
    }

    Node* n = new Node(d);
    tail->next = n;
    tail = n;
}

void printList(Node* head){

    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
    return;
}

Node* reverse_in_group_of_k(Node* head, int k){

    Node* prev = NULL, *curr = head, *nextt = NULL;
    int ct = 0;


        /*reverse first k nodes of the linked list */
        while(curr != NULL && ct < k){
            nextt = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nextt;
            ct++;
        }
        /* next is now a pointer to (k+1)th node
        Recursively call for the list starting from current.
        And make rest of the list as next of first node */
        if(nextt != NULL){
            head->next = reverse_in_group_of_k(nextt,k);
        }

    /* previous is new head of the input list */
    return prev;
}

int main(){

    Node* head = NULL, *tail = NULL;

    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);
    insertAtTail(head,tail,6);
    insertAtTail(head,tail,7);
    insertAtTail(head,tail,8);

    printList(head);

    head = reverse_in_group_of_k(head,3);

    printList(head);


return 0;
}

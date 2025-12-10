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

Node* mid(Node* head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* fast = head->next, *slow = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeSort(Node* a){

    if(a == NULL || a->next == NULL){
        return a;
    }

    /// Recursive case
    ///1. Break Linked List into 2 part
    Node* mid_point = mid(a);
    Node* left = a;
    Node* right = mid_point->next;

    mid_point->next = NULL;

    ///2. Recursively sort 2 parts

    left = mergeSort(left);
    right = mergeSort(right);

    ///3. Merge sorted Linked List

    Node* c = merge_sorted_lists(left,right);

    return c;
}

int main(){


    Node* head = NULL, *tail = NULL;

    insertAtTail(head,tail,10);
    insertAtTail(head,tail,77);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,67);
    insertAtTail(head,tail,1);

    printList(head);

    head = mergeSort(head);

    printList(head);

return 0;
}

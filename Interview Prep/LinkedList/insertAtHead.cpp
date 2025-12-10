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

void printList(Node* head){

    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}

int main(){

    Node* head = NULL;

    insertAtHead(head,3);
    insertAtHead(head,23);
    insertAtHead(head,45);
    insertAtHead(head,7);

    printList(head);

    insertAtMiddle(head,99,2);
    insertAtTail(head,101);

    printList(head);

return 0;
}

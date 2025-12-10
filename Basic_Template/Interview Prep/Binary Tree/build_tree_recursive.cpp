#include<bits/stdc++.h>
using namespace std;

class node{

public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree(){

    int d;  cin>>d;

    if(d == -1){
        return NULL;
    }

    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void printTree_1(node* root){  /// pre order

    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    printTree_1(root->left);
    printTree_1(root->right);
}

void printTree_2(node* root){  /// in order

    if(root == NULL){
        return;
    }

    printTree_2(root->left);
    cout<<root->data<<" ";
    printTree_2(root->right);
}

void printTree_3(node* root){  /// post order

    if(root == NULL){
        return;
    }

    printTree_3(root->left);
    printTree_3(root->right);
    cout<<root->data<<" ";
}


int main(){

    node* root = buildTree();

    printTree_1(root);
}

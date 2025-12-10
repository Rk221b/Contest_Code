#include<bits/stdc++.h>
using namespace std;

class node{

public:

    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


node* buildTree_Level_Wise(){

    int d;

    cout<<"Enter Data"<<endl;
    cin>>d;

    if(d == -1){
        return NULL;
    }

    queue<node*> pendingNodes;
    node* root = new node(d);

    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        node* front_element = pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter left child of "<<front_element->data<<endl;
        int left_data;
        cin>>left_data;

        if(left_data != -1){
            node* left_child = new node(left_data);
            front_element->left = left_child;
            pendingNodes.push(left_child);
        }

        cout<<"Enter right child of "<<front_element->data<<endl;
        int right_data;
        cin>>right_data;

        if(right_data != -1){
            node* right_child = new node(right_data);
            front_element->right = right_child;
            pendingNodes.push(right_child);
        }
    }

    return root;
}

node* LCA(node* root, int a, int b){

    if(root == NULL){
        return NULL;
    }

    if(root->data == a || root->data == b){
        return root;
    }

    node* leftAns = LCA(root->left,a,b);
    node* rightAns = LCA(root->right,a,b);

    if(leftAns != NULL && rightAns != NULL){
        return root;
    }

    if(leftAns != NULL){
        return leftAns;
    }
    return rightAns;
}

int main(){

    node* root = buildTree_Level_Wise();

    cout<<"Enter nodes for which you want to find LCA"<<endl;
    int a,b;   cin>>a>>b;

    node* lca = LCA(root,a,b);

    if(lca != NULL)
        cout<<"LCA of "<<a<<" "<<b<<" is "<<lca->data<<endl;

return 0;
}

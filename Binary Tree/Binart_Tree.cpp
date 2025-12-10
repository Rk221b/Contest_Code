#include<bits/stdc++.h>
#include<queue>
using namespace std;

template <typename T>
class BinaryTree{

public:
    T data;
    BinaryTree* left;
    BinaryTree* right;

 BinaryTree(T data){   /// Constructor
  this->data = data;
  left = NULL;
  right = NULL;
 }

 ~BinaryTree(){   /// Destructor
   delete left;
   delete right;
 }
};

BinaryTree<int>* takeInputLevelWise(){

int rootData;
cout<<"Enter Root Data"<<endl;
cin>>rootData;
BinaryTree<int>* root = new BinaryTree<int>(rootData);

queue<BinaryTree<int>*> pendingNodes;
pendingNodes.push(root);

while(!pendingNodes.empty()){

    BinaryTree<int>* frontElement = pendingNodes.front();
    pendingNodes.pop();

    int leftData;
    cout<<"Enter Left Child Data of : "<<frontElement->data<<endl;
    cin>>leftData;

    if(leftData != -1){
        BinaryTree<int>* leftChild = new BinaryTree<int>(leftData);
        frontElement->left = leftChild;
        pendingNodes.push(leftChild);
    }

    int rightData;
    cout<<"Enter Right Child Data of : "<<frontElement->data<<endl;
    cin>>rightData;

    if(rightData != -1){
        BinaryTree<int>* rightChild = new BinaryTree<int>(rightData);
        frontElement->right = rightChild;
        pendingNodes.push(rightChild);
    }
}
return root;
}


BinaryTree<int>* takeInput(){

int rootData;
cout<<"Enter Data"<<endl;
cin>>rootData;

if(rootData == -1){
    return NULL;
}

BinaryTree<int>* root = new BinaryTree<int>(rootData);

BinaryTree<int>* childleft = takeInput();
root->left = childleft;

BinaryTree<int>* childright = takeInput();
root->right = childright;

return root;
}

void print(BinaryTree<int>* root){

if(root == NULL){
    return;
}

cout<<root->data<<" : ";

if(root->left != NULL){
    cout<<" L"<<root->left->data<<" , ";

}
if(root->right != NULL){
    cout<<" R"<<root->right->data<<" , ";
}
cout<<endl;
print(root->left);
print(root->right);
}

void mirrorBinaryTree(BinaryTree<int>* root) {

    if(root == NULL){
        return;
    }
    BinaryTree<int>* temp;

    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);

    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main(){

/*
BinaryTree<int>* root = new BinaryTree<int>(1);
BinaryTree<int>* node1 = new BinaryTree<int>(2);
BinaryTree<int>* node2 = new BinaryTree<int>(3);

root->left = node1;
root->right = node2;
*/

BinaryTree<int>* root = takeInputLevelWise();
print(root);

mirrorBinaryTree(root);
print(root);

return 0;
}

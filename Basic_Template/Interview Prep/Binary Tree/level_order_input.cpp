#include<bits/stdc++.h>
#include<queue>
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

void printTree(node* root){

    if(root == NULL){
        return;
    }

    cout << root->data << ":";
	if (root->left != NULL) {
		cout << "L" << root->left->data;
	}

	if (root->right != NULL) {
		cout << "R" << root->right->data;
	}
	cout << endl;
	printTree(root->left);
	printTree(root->right);
}

int height(node* root){

    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return max(left,right)+1;
}

int diameter(node* root){   /// O(n^2) approach

    if(root == NULL){
        return 0;
    }

    int h1 = height(root->left);
    int h2 = height(root->right);

    int op1 = h1 + h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1,max(op2,op3));
}

class Pair{

public:
    int height, diameter;
};

Pair fastDiameter(node* root){  /// O(n) approach

    Pair p;

    if(root == NULL){
        p.height = 0, p.diameter = 0;
        return p;
    }

    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = 1 + max(left.height,right.height);
    p.diameter = max(left.height+right.height, max(left.diameter,right.diameter));

    return p;
}

void printKthLevel(node* root, int k){

    if(root == NULL){
        return;
    }

    if(k == 1){
        cout<<root->data<<" ";
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
}

void printAllLevels(node* root){

    int H = height(root);

    for(int i=1;i<=H;i++){
        printKthLevel(root,i);
         cout<<endl;
    }
    return;
}

void printRightView(node* root, int level, int &maxlevel){  /// we will follow order of root,right,left

    if(root == NULL){
        return;
    }

    if(level > maxlevel){ /// means we are visiting the new level for first time
        cout<<root->data<<" ";
        maxlevel = level;
    }

    printRightView(root->right,level+1,maxlevel);
    printRightView(root->left,level+1,maxlevel);
}

int main(){

    node* root = buildTree_Level_Wise();

   // printTree(root);
   //printAllLevels(root);

  // cout<<diameter(root)<<endl;

  Pair p = fastDiameter(root);

  cout<<"Height "<<p.height<<endl;
  cout<<"Diameter "<<p.diameter<<endl;

   int maxlevel = -1;
  printRightView(root, 0, maxlevel);
}

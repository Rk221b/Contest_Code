#include<bits/stdc++.h>
using namespace std;

void build(int arr[], int s, int e, int *tree, int index){

    if(s == e){
        tree[index] = arr[s];
        return;
    }

    /// build left, right using mid

    int mid = (s+e)/2;

    build(arr, s, mid, tree, 2*index);
    build(arr, mid+1, e, tree, 2*index+1);

    tree[index] = min(tree[2*index], tree[2*index+1]);

}

int query(int *tree, int s, int e, int qs, int qe, int index){

    /// Complete Overlap
    if(s >= qs && e <= qe){
        return tree[index];
    }

    /// No overlap
    if(s > qe || e < qs){
        return INT_MAX;
    }

    /// Partial Overlap call both side
    int mid = (s+e)/2;

    int left = query(tree, s, mid, qs, qe, 2*index);
    int right = query(tree, mid+1, e, qs, qe, 2*index+1);

    return min(left, right);
}

void update(int *tree, int s, int e, int i, int value, int treeindex){

    /// out of bound
    if(i > e || i < s){
        return;
    }

    if(s == e){
        tree[treeindex] = value;
        return;
    }

    /// call both side
    int mid = (s+e)/2;

    update(tree, s, mid, i, value, 2*treeindex);
    update(tree, mid+1, e, i, value, 2*treeindex+1);

    tree[treeindex] = min(tree[2*treeindex],tree[2*treeindex+1]);

}

void updateRange(int *tree, int s, int e, int rs, int re , int value, int treeindex){

    /// out of bound
    if(rs > e || re < s){
        return;
    }

    if(s == e){
        tree[treeindex] = value;
        return;
    }

    /// call both side
    int mid = (s+e)/2;

    update(tree, s, mid, rs, re, value, 2*treeindex);
    update(tree, mid+1, e, rs, re, value, 2*treeindex+1);

    tree[treeindex] = min(tree[2*treeindex],tree[2*treeindex+1]);

    return;
}

int main(){

    int n;  cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int *tree = new int[4*n+1];
    memset(tree,0,sizeof(tree));

    build(arr,0,n-1,tree,1);

    /// print tree
    for(int i=1;i<=4*n;i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;

    int q;  cin>>q;


    while(q--){
        int l,r;  cin>>l>>r;

        cout<<query(tree, 0, n-1, l, r, 1)<<endl;
    }


return 0;
}

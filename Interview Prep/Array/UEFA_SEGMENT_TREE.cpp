/*
https://www.codechef.com/INTW2020/problems/UCL1
*/
#include<bits/stdc++.h>
#include<vector>
#define INF 1e15
#define ll long long int
ll power(ll x, ll y){ll res=1;while(y>0){if(y&1)res = (res*x);y = y>>1;x = (x*x);}return res;}

using namespace std;

const ll N = 500000;
ll total;


struct team{

    ll defence, attack, midfield,idx;
    team()
    {
        defence=-INF;
        midfield=-INF;
        attack=-INF;
        idx=0;
    }

};


void build(vector<team> &tree, vector<team> &arr, ll s, ll e, ll treeIndex){

   /// Base Case
   if(s == e){
    tree[treeIndex] = arr[s];
    return;
   }

   ll mid = (s+e)/2;

   build(tree, arr, s, mid, 2 * treeIndex);
   build(tree, arr, mid + 1, e, 2 * treeIndex + 1);


   team left = tree[2 * treeIndex];
   team right = tree[2 * treeIndex + 1];
   ll ct = 0;

   if(right.attack > left.attack){
    ct++;
   }
   if(right.defence > left.defence){
    ct++;
   }
   if(right.midfield > left.midfield){
    ct++;
   }

   if(ct >= 2){
    tree[treeIndex] = right;
   }
   else{
    tree[treeIndex] = left;
   }
}

void update(vector<team> &tree, ll s, ll e, ll t1, team val, ll treeIndex){

    if(t1 < s || t1 > e){   /// out of bound
        return;
    }

    if(s == e){
        tree[treeIndex] = val;
        return;
    }

     /// call both side
    ll mid = (s+e)/2;

    update(tree, s, mid, t1, val, 2*treeIndex);
    update(tree, mid+1, e, t1, val, 2*treeIndex+1);


   team left = tree[2 * treeIndex];
   team right = tree[2 * treeIndex + 1];
   ll ct = 0;

   if(right.attack > left.attack){
    ct++;
   }
   if(right.defence > left.defence){
    ct++;
   }
   if(right.midfield > left.midfield){
    ct++;
   }

   if(ct >= 2){
    tree[treeIndex] = right;
   }
   else{
    tree[treeIndex] = left;
   }
}

vector<team> tree(500000);

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll x;  cin>>x;

    total = power(2,x);

    vector<team> arr(total);
    ll d,a,m;

    for(int i=0;i<total;i++){
        cin>>a>>m>>d;
        arr[i].attack   = a;
        arr[i].midfield = m;
        arr[i].defence  = d;
        arr[i].idx      = i+1;
    }

    build(tree, arr, 0, total - 1 , 1);

 //   for(int i=0;i<total;i++){
 //       cout<<tree[i].idx<<endl;
 //   }

    ll q;  cin>>q;
    char c;
    int s1,s2;

    while(q--){
        cin>>c>>s1>>s2;
        s1--;
        s2--;

        team value_s1 = arr[s1];
        value_s1.idx = s2 + 1;

        team value_s2 = arr[s2];
        value_s2.idx = s1 + 1;

        arr[s1] = value_s2;
        arr[s2] = value_s1;

        update(tree, 0, total - 1, s1, value_s2, 1);
        update(tree, 0, total - 1, s2, value_s1, 1);

        cout<<tree[1].idx<<endl;
    }

return 0;
}

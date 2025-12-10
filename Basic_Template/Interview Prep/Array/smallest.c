/*
https://codeforces.com/problemset/problem/91/B
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void update(ll *tree, int s, int e, int idx, int value, int treeIndex){

    /// Out of Bound
    if(idx < s || idx > e){
        return;
    }

    /// Complete overlap
    if(s == e){
        tree[treeIndex] = value;
        return;
    }

    /// Call both side
    int mid = (s+e)/2;

    update(tree, s, mid, idx, value, 2*treeIndex);
    update(tree, mid+1, e, idx, value, 2*treeIndex+1);

    tree[treeIndex] = tree[2*treeIndex] + tree[2*treeIndex+1];

}

ll query(ll *tree, int s, int e, int qs, int qe, int treeIndex){

    /// Out of Bound
    if(qe < s || qs > e){
        return 0;
    }

    /// Complete overlap
    if(s >= qs && e <= qe){
        return tree[treeIndex];
    }

    /// Call both side
    int mid = (s+e)/2;

    ll left  = query(tree, s, mid, qs, qe, 2*treeIndex);
    ll right = query(tree, mid+1, e, qs, qe, 2*treeIndex+1);

    return (left + right);

}

int main(){

    int t;  cin>>t;

    while(t--){
        ll n;  cin>>n;
        ll arr[n];

        ll *tree = new ll[4*n+1];

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        for(int i=0;i<=4*n;i++){
           // update(tree, 0, n-1, i, arr[i], 1);
           tree[i] = 0;
          // cout<<tree[i]<<endl;
        }

        ll res[n];

        for(int i=0;i<n;i++){
            res[i] = 0;
        }

        /// offline query concept
        vector<pair<ll,int>> v;

        for(int i=0;i<n;i++){
            v.push_back(make_pair(arr[i],i));
        }

        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        for(int i=0;i<n;i++){
            ll value = v[i].first;
            int index = v[i].second;

            res[index] = query(tree,0,n-1,0,index,1);
            update(tree,0,n-1,index,1,1);
        }

        ll inversion_count = 0;

        for(int i=0;i<n;i++){
          //  cout<<v[i].first<<" "<<v[i].second<<" "<<res[v[i].second]<<endl;
            inversion_count += res[v[i].second];
        }
        //cout<<endl;
        cout<<inversion_count<<endl;
    }

return 0;
}

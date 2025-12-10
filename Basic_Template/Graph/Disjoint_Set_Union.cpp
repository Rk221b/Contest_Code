#include<bits/stdc++.h>
#include<vector>
#define ll long long int
using namespace std;

struct dsu{

    vector<int> par;
    vector<int> sz;
    int total_components;

    /// Initialize
    void init(int n){
        par.resize(n);
        sz.resize(n);   /// To store size of every compoment
        total_components = n;

        for(int i=0;i<n;i++){
            par[i] = i;
            sz[i] = 1;
        }
    }

    int get_superparent(int x){

        if(par[x] == x){
            return x;
        }
        return par[x] = get_superparent(par[x]);  /// compressing the path also
    }

    void unite(int x, int y){

     int super_parent_x = get_superparent(x);
     int super_parent_y = get_superparent(y);

     if(super_parent_x != super_parent_y){
        par[super_parent_x] = super_parent_y;
        total_components--;

        /// Update size of component
        sz[super_parent_y] += sz[super_parent_x];
        sz[super_parent_x] = 0;
     }
    }
}G;

int main(){

        int n,m;  cin>>n>>m;

        G.init(n);

        int x,y;

        for(int i=0;i<m;i++){
            cin>>x>>y;
            G.unite(x,y);
        }
        ll ans = 0;

        for(int i=0;i<n;i++){
            int super_parent = G.get_superparent(i);
            ans += (n - G.sz[super_parent]);
        }
        ans /= 2;

        cout<<ans<<"\n";

return 0;
}

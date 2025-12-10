#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct dsu{

    vector<int> par;

    void init(int n){
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }

    int get_super_parent(int x){
        if(par[x] == x)
            return x;
        else{
            return par[x] = get_super_parent(par[x]);
        }
    }

    void unit(int x, int y){

        int super_parent_x = get_super_parent(x);
        int super_parent_y = get_super_parent(y);

        if(super_parent_x != super_parent_y){
            par[super_parent_x] = super_parent_y;
        }
    }
};



int main(){

  int n,m;  cin>>n>>m;

    dsu G;
    G.init(n);

    int x,y;
    bool cycle = 0;

    for(int i=0;i<m;i++){
        cin>>x>>y;

        int super_parent_x = G.get_super_parent(x);
        int super_parent_y = G.get_super_parent(y);

        if(super_parent_x != super_parent_y){
            G.unit(x,y);
        }
        else{
            cycle = 1;
            break;
        }
    }

    if(cycle == 0){
        cout<<"Graph has no Cycle"<<"\n";
    }
    else{
        cout<<"Graph has Cycle"<<"\n";
    }

return 0;
}


#include<bits/stdc++.h>
#include<vector>

using namespace std;

vector<int> graph[100005];
int tin[100005], tout[100005], timer;

void euler_tour_1(int cur, int par){

    cout<<cur<<" ";

    for(auto nbr : graph[cur]){
        if(nbr != par){
            euler_tour_1(nbr,cur);
            cout<<cur<<" ";
        }
    }
return;
}

void euler_tour_2(int cur, int par){   /// time in and time out concept

    cout<<cur<<" ";
    tin[cur] = timer++;
    for(auto nbr : graph[cur]){
        if(nbr != par){
            euler_tour_2(nbr,cur);
        }
    }
    cout<<cur<<" ";
    tout[cur] = timer++;
return;
}

void euler_tour_3(int cur, int par){   /// normal DFS

    cout<<cur<<" ";
    /// when entering node
    tin[cur] = ++timer;
    for(auto nbr : graph[cur]){
        if(nbr != par){
            euler_tour_3(nbr,cur);
        }
    }

    /// when leaving node
    tout[cur] = timer;

return;
}

/// function which tells is x is ancestor y or not

bool is_ancestor(int x, int y){
    return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int main(){

    int n;  cin>>n;
    int x,y;

    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }


    //euler_tour_1(1,0);
    //cout<<endl;
    timer = 1;
    euler_tour_2(1,0);
    cout<<endl;

    for(int i=1;i<=n;i++){
        cout<<i<<" "<<tin[i]<<" "<<tout[i]<<endl;
    }

    timer = 0;
    euler_tour_3(1,0);
    cout<<endl;

   for(int i=1;i<=n;i++){
        cout<<i<<" "<<tin[i]<<" "<<tout[i]<<endl;
    }

    if(is_ancestor(1,7)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }


return 0;
}

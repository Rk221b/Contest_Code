/*
Find the smallest value node in subtree of X.
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 100;

vector<int> tree[N];
int DP[N];  /// DP[i] represents smallest value node in subtree of i

void dfs(int cur, int par){

    DP[cur] = cur;

    for(auto x : tree[cur]){
        if(x != par){
            dfs(x,cur);

            DP[cur] = min(DP[cur], DP[x]);
        }
    }
return;
}

int main(){

    int n; cin>>n;
    int x,y;

    for(int i=0;i<n-1;i++){
            cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    dfs(1,0);

    for(int i=1;i<=n;i++){
        cout<<i<<" "<<DP[i]<<endl;
    }


return 0;
}

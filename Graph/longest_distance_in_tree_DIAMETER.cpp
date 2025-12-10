/*
https://www.spoj.com/problems/PT07Z/
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 10005;
vector<int> graph[N];
int maxDistance, maxNode;

void dfs(int cur, int par, int depth){

    if(maxDistance < depth){
        maxDistance = depth;
        maxNode = cur;
    }

    for(auto x:graph[cur]){
        if(x != par){
            dfs(x,cur,depth+1);
        }
    }
return;
}

int main(){

    int n;  cin>>n;
    int x,y;

    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    maxDistance = -1;

    dfs(1,0,0);

    /// maxNode must have been updated till now
    dfs(maxNode,0,0);

    cout<<maxDistance<<endl;

return 0;
}

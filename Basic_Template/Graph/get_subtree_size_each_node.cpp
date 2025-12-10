#include<bits/stdc++.h>
using namespace std;

const int N = 10005;
vector<int> graph[N];
int subtreeSize[N];

int dfs(int cur, int par){

    int cur_size = 1;

    for(auto x:graph[cur]){
        if(x != par){
           cur_size += dfs(x,cur);
        }
    }

   subtreeSize[cur] = cur_size;
   return cur_size;
}

int main(){

    int n;  cin>>n;
    int x,y;

    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    memset(subtreeSize,0,sizeof(subtreeSize));

    dfs(1,0);

    for(int i=1;i<=n;i++)
    cout<<i<<" "<<subtreeSize[i]<<endl;

return 0;
}

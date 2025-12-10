/*
https://codeforces.com/problemset/problem/1244/D
*/

#include<bits/stdc++.h>
#include<list>

using namespace std;

void dfs(list<int> l[],int start, bool visited[], vector<int>& v){

 //cout<<start<<" ";
 v.push_back(start);
 visited[start] = true;

 for(auto neighbr:l[start]){
    if(!visited[neighbr]){
        dfs(l,neighbr,visited,v);
    }
 }

}

int main(){

int n;  cin>>n;
list<int> l[n+1];

int a[n+1],b[n+1],c[n+1];

for(int i=1;i<=n;i++){
    cin>>a[i];
}

for(int i=1;i<=n;i++){
    cin>>b[i];
}

for(int i=1;i<=n;i++){
    cin>>c[i];
}

int u,v,flag = 0;

for(int i=1;i<=n-1;i++){
    cin>>u>>v;
    l[u].push_back(v);
    l[v].push_back(u);

    if(l[u].size() > 2 || l[v].size() > 2){
        flag = 1;
    }
}

if(flag == 1){
    cout<<-1<<endl;
}
else{
    int arr[n+1];

    bool visited[n+1];

    for(int i=1;i<=n;i++){
        visited[i] = false;
    }

    int leaf = -1;

    for(int i=1;i<=n;i++){
        if(l[i].size() == 1){
            leaf = i;
            break;
        }
   }
   // cout<<leaf<<endl;
    vector<int> v;
    dfs(l,leaf,visited,v);

    for(auto i:v){
        cout<<i<<" ";
    }

}

return 0;
}

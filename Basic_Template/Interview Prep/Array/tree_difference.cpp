#include <iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;

bool printDFS(int** edges, int n, int sv,int ev, bool* visited,vector<int> &vc){

  //cout<<sv<<endl;
    visited[sv] = true;
  if(sv == ev){
     vc.push_back(sv);
    return true;
  }

  for(int i=0;i<n;i++){
     if(i == sv){
       continue;
    }
    if(edges[sv][i] == 1){

       if(visited[i]){
         continue;
       }
    printDFS(edges , n , i , ev ,visited,vc);
      if(visited[ev]){
      vc.push_back(sv);
      return true;
      }
    }
  }
  return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

int t;  cin>>t;

while(t--){
    int n,q;
    cin >> n >> q;
    int cost[n];

    for(int i=0;i<n;i++){
        cin>>cost[i];
    }

    int e = n-1;

    int** edges = new int*[n];

    for(int i=0;i<n;i++){
        edges[i] = new int[n];

        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }

        for(int i=0;i<e;i++){
            int f,s;
            cin >> f >> s;

            edges[f-1][s-1] = 1;
            edges[s-1][f-1] = 1;
        }
      map<pair<int,int>,int> dp;

      while(q--){

        int v1,v2;
        cin>>v1>>v2;
        v1--;
        v2--;

        if(dp.find(make_pair(v1,v2)) != dp.end()){
           cout<<dp[make_pair(v1,v2)]<<endl;
        }

        else if(dp.find(make_pair(v2,v1)) != dp.end()){
           cout<<dp[make_pair(v2,v1)]<<endl;
        }

        else{

        bool* visited = new bool[n];

        for(int i=0;i<n;i++){
            visited[i]=false;
        }

        vector<int> vc;
        vector<int>::iterator it;
        vector<int>c;
        int ans = INT_MAX;

        if(printDFS(edges,n,v1,v2,visited,vc)){

            for(it=vc.begin();it!=vc.end();it++){
                //cout<<*it<<" ";
                c.push_back(cost[*it]);
                }
           // sort(c.begin(),c.end());
            int sz = c.size();

                for(int i=0;i<sz;i++){
                  for(int j=i+1;j<sz;j++){
                    ans = min(ans,abs(c[i]-c[j]));
                  }
                }
            }

            dp[make_pair(v1,v2)] = ans;
            dp[make_pair(v2,v1)] = ans;
            cout<<ans<<"\n";
        }
      }
}
  return 0;
}

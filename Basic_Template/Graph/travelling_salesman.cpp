/*
Travelling Salesman Problem
https://www.spoj.com/problems/PESADA04/
*/
#include<bits/stdc++.h>
#define ll long long int
#define inf 1e10
using namespace std;


ll tsp(int VISITED_ALL, int mask, int city, int** dist, int n, int** DP){

    /// Base Case
    if(mask == VISITED_ALL){
        return dist[city][0];
    }

    /// Look up
    if(DP[mask][city] != -1){
        return DP[mask][city];
    }

    ll ans = inf;

    for(int i=0;i<n;i++){

        if((mask & (1<<i)) == 0){   /// If city is not visited
            ll smallAns = dist[city][i] + tsp(VISITED_ALL, (mask|(1<<i)), i, dist, n, DP);

            ans = min(ans, smallAns);
        }
    }
  //  cout<<ans<<endl;
    return DP[mask][city] = ans;
}


int main(){

    int t;  cin>>t;

    while(t--){

       int n;  cin>>n;  /// number of city;
       n++; /// according to problem statement origin city is not counted in n

       int sz = (n*n) - n;

       int input[sz];

       for(int i=0;i<sz;i++){  /// Because in input we are not provided cost to travel to same city which is 0
        cin>>input[i];
       }

       int k = 0;

       int** dist = new int*[n];
       for(int i=0;i<n;i++){
        dist[i] = new int[n];
        for(int j=0;j<n;j++){
            if(i == j){
                dist[i][j] = 0;
            }
            else{
                dist[i][j] = input[k];
                k++;
            }
       //     cout<<dist[i][j]<<" ";
        }
      //   cout<<endl;
       }

       int r = pow(2,n);

       int** DP = new int*[r];
       for(int i=0;i<r;i++){
        DP[i] = new int[n];
        for(int j=0;j<n;j++){
            DP[i][j] = -1;
        }
       }


       int VISITED_ALL = (1<<n)-1;

       int mask = 1;   /// 0001
       int start_city = 0;

       ll ans = tsp(VISITED_ALL, mask, start_city, dist, n, DP);

       cout<<ans<<endl;

    }


return 0;
}

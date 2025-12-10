/*
https://codeforces.com/problemset/problem/1221/D
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const long long INF64 = (long long)(1e18) + 100;

int main(){

  int t;  scanf("%d", &t);


  while(t--){

    int n;  scanf("%d", &n);
    ll a[n],b[n];

    for(int i=0;i<n;i++){
        scanf("%lld", a + i);
        scanf("%lld", b + i);
    }

    /// Here we are taking 3 possible state for any element as increasing any element by at most 3 will be sufficient

    ll dp1[3][n];    /// dp1[i][j] represents value of element j by i

    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            dp1[i][j] = a[j] + i;
        }
    }

 /*
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            cout<<dp1[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
*/

    ll dp2[3][n];   /// dp2[i][j] represents cost of incrementing element j by i

    /// Base case will be that cost of incrementing 1st element doesn't depend on any state as its the first state

    for(int i=0;i<3;i++){
        dp2[i][0] = b[0] * (i);
    }

    ll mn;

    for(int i=1;i<n;i++){


        for(int j=0;j<3;j++){

                mn = INF64;

                if(dp1[j][i] != dp1[0][i-1])
                {
                mn = min(mn, dp2[0][i-1]);
                }

                if(dp1[j][i] != dp1[1][i-1])
                {
                mn = min(mn, dp2[1][i-1]);
                }

                if(dp1[j][i] != dp1[2][i-1])
                {
                mn = min(mn, dp2[2][i-1]);
                }

                dp2[j][i] = mn + (b[i] * j);
        }
    }

    ll ans = INF64;

    for(int i=0;i<3;i++){
        ans = min(ans,dp2[i][n-1]);
    }
    //cout<<ans<<"\n";
    printf("%lld\n", ans);
  }

return 0;
}

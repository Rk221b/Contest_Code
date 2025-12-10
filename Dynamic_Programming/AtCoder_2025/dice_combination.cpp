// https://cses.fi/problemset/task/1633
#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;


int main(){

 int n; cin>>n;
 vector<int> dp(n+1,0);

 dp[0] = 1;

 for(int sum=1;sum<=n;sum++){
    for(int dice=1;dice<=6;dice++){
        if(sum-dice >= 0){
            dp[sum] = (dp[sum]%MOD + dp[sum-dice]%MOD)%MOD;
        }
    }
 }

 cout<<dp[n]<<"\n";


return 0;
}

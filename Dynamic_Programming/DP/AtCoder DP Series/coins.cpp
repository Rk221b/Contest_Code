/*
https://atcoder.jp/contests/dp/tasks/dp_i
*/
#include<bits/stdc++.h>
using namespace std;

/// dp[i][x] is the probablity of getting atleast ( >= x) heads on tossing first ith coins
const int N = 3001;

double dp[N][N];

double solve(vector<double>& p, int i,int x){

    if(x == 0){
        return 1;
    }
    if(i == 0){
        return 0;
    }
    if(dp[i][x] >= -0.9){
        return dp[i][x];
    }

    return dp[i][x] = p[i]*solve(p,i-1,x-1) + (1 - p[i])*solve(p,i-1,x);
}

int main(){

    int n;  cin>>n;
    vector<double> p(n+1);

    for(int i=1;i<=n;i++){
        cin>>p[i];
    }

    memset(dp,-1,sizeof(dp));

    double ans = solve(p,n,(n+1)/2);

    cout<<fixed<<setprecision(10)<<ans<<endl;

return 0;
}

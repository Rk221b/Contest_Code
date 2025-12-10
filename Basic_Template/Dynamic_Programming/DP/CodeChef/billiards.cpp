/*
https://www.codechef.com/LRNDSA07/problems/CDQU5
*/
#include<bits/stdc++.h>
#define mod 1000000009
#define ll long long int
using namespace std;

const int N = 1000005;
ll dp[N];


int main(){

        dp[0] = 1;
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 1;

        for(int i=4;i<N;i++){
            dp[i] = (dp[i-2] + dp[i-3])%mod;
        }

        int t;   cin>>t;

        while(t--){

           int x;  cin>>x;

           cout<<dp[x]<<endl;
        }


return 0;
}


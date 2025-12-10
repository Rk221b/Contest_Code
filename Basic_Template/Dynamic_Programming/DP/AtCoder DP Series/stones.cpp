/*
https://atcoder.jp/contests/dp/tasks/dp_k
*/
#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,k;  cin>>n>>k;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int dp[k+1];

    memset(dp,0,sizeof(dp));

    /// dp[i] = 0 represents that ith posotion is loosing position and dp[i]=1 represents that its a winning position

    for(int i=1;i<=k;i++){
        for(auto pos:arr){
            if(pos <= i){
                if(dp[i-pos] == 0){
                    dp[i] = 1;
                }
            }
        }
    }

    if(dp[k] == 0) cout<<"Second"<<endl;
    else cout<<"First"<<endl;

return 0;
}

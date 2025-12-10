/*
https://www.codechef.com/LRNDSA07/problems/SUBINC
*/
#include<bits/stdc++.h>
using namespace std;

long long int dp[100005];

int main(){

        int t;   cin>>t;

        while(t--){

            memset(dp,-1,sizeof(dp));
            int n;  cin>>n;

            long long int arr[n];

            for(int i=0;i<n;i++){
                cin>>arr[i];
                dp[i] = 1;
            }

            long long int ans = dp[0];

            for(int i=1;i<n;i++){
                if(arr[i] >= arr[i-1]){
                    dp[i] = dp[i] + dp[i-1];
                }
                ans += dp[i];
            }

            cout<<ans<<endl;
        }


return 0;
}


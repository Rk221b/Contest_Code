/*
https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d40bb
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 51;
const int P = 51*31;

int dp[N][P];    ///  here dp[i][j] denotes currently on ith stack and jth plates taken so far
int preSum[N][32];
int n,k,p;


int solve(int currStackIdx, int platesTakenSoFar){

 /// Base Cases

 if(platesTakenSoFar == p){
    return 0;
 }
 if(currStackIdx >= n || platesTakenSoFar > p){
    return -1e9;
 }
 if(dp[currStackIdx][platesTakenSoFar] != -1){
    return dp[currStackIdx][platesTakenSoFar];
 }

 /// Recursive Case
 int ans = -1e9;
 for(int i=0;i<=k;i++){
    int temp = preSum[currStackIdx][i] + solve(currStackIdx+1,platesTakenSoFar+i);
    ans = max(ans,temp);
 }

return dp[currStackIdx][platesTakenSoFar] = ans;
}


int main(){

    int t;  cin>>t;
    int tnum = 1;

    while(t--){
        cin>>n>>k>>p;

        int arr[n][k+1];
        memset(dp,-1,sizeof(dp));
        memset(preSum,0,sizeof(preSum));
        memset(arr,0,sizeof(arr));

        for(int i=0;i<n;i++){
            for(int j=1;j<=k;j++){
                cin>>arr[i][j];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=1;j<=k;j++){
                preSum[i][j] = preSum[i][j-1] + arr[i][j];
            }
        }


        int ans = solve(0,0);

        cout<<"Case #"<<tnum<<": "<<ans<<endl;

        tnum++;
    }


return 0;
}

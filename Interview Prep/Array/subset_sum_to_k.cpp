/*
Total number of subsets that give sum = k
*/
#include<bits/stdc++.h>

using namespace std;

int subset_sum_to_k(int arr[], int n, int k){

    if(n == 0 && k == 0){
        return 1;
    }
    if(n == 0 && k != 0){
        return 0;
    }

    /// At each point we can include or exclude any element

    int op1 = 0 ,op2 = 0;

    op1 = subset_sum_to_k(arr,n-1,k-arr[n-1]); /// including
    op2 = subset_sum_to_k(arr,n-1,k); /// not including

    return op1+op2;
}

int subset_sum_to_k_dp(int arr[], int n, int k, int **dp){

    if(n == 0 && k == 0){
        return 1;
    }
    if(n == 0 && k != 0){
        return 0;
    }

    /// Look Up
    if(dp[n][k] != -1){
        return dp[n][k];
    }

    /// At each point we can include or exclude any element

    int op1 = 0 ,op2 = 0;

    op1 = subset_sum_to_k(arr,n-1,k-arr[n-1]); /// including
    op2 = subset_sum_to_k(arr,n-1,k); /// not including

    /// Memoization
    dp[n][k] = op1+op2;
    return dp[n][k];
}

int main(){

cout<<"Number of Elements in array along with desired sum"<<endl;

int n,k; cin>>n>>k;

int arr[n];

cout<<"Enter array elements"<<endl;

for(int i=0;i<n;i++){
    cin>>arr[i];
}

int ans1 = subset_sum_to_k(arr,n,k);

cout<<ans1<<endl;

/// DP version starts here

/// DP array of size (n+1)*(k+1)

int **dp = new int*[n+1];
for(int i=0;i<=n;i++){
    dp[i] = new int[k+1];
    for(int j=0;j<=k;j++){
        dp[i][j] = -1;
    }
}

int ans2 = subset_sum_to_k_dp(arr,n,k,dp);

cout<<ans2<<endl;

return 0;
}

#include<bits/stdc++.h>
using namespace std;

int solve(int sum, int coin[], int n){

    if(sum == 0) return 1;
    if(sum > 0 && n == 0) return 0;

    ///unbounded knapsack
    if(sum < coin[n-1]){
        return solve(sum,coin,n-1);
    }
    else{
        return solve(sum,coin,n-1) + solve(sum-coin[n-1],coin,n);
    }
}

int main(){

cout<<"Enter Sum along with number of coins"<<endl;
int sum,n;  cin>>sum>>n;
int coin[n];

cout<<"Enter value of each coin"<<endl;
for(int i=0;i<n;i++){
    cin>>coin[i];
}

int ways = solve(sum,coin,n);

cout<<ways<<endl;

return 0;
}

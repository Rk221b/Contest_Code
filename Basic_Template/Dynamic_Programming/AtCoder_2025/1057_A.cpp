/*
https://codeforces.com/contest/2153/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    int t;
    cin>>t;

    while(t--){

     int n; cin>>n;

     vector<ll> arr(n,0);

     for(int i=0;i<n;i++){
        cin>>arr[i];
     }

    ll ans = 1;

    sort(arr.begin(),arr.end());

    int last = arr[0];

    for(int i=1;i<n;i++){
        if(arr[i] > last){
            last = arr[i];
            ans++;
        }
    }

    cout<<ans<<"\n";

    }

return 0;
}


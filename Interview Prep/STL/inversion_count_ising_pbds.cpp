/*
https://www.spoj.com/problems/INVCNT/
Author: Ritik Kapoor
*/
// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace __gnu_pbds;
using namespace std;

// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    new_data_set;


int main(){

ll t;  cin>>t;

while(t--){
    ll n;  cin>>n;
    ll arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    new_data_set S;
    ll ans = 0;

    for(int i=0;i<n;i++){
        S.insert(arr[i]);
        ans = ans + (S.size() - S.order_of_key(arr[i]+1));
    }
    cout<<ans<<endl;
}

return 0;
}

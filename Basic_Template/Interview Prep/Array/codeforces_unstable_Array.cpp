/*
https://codeforces.com/contest/1353/problem/A
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

    ll t;  cin>>t;

    while(t--){
        ll n,m;  cin>>n>>m;

        if(n == 1){
            cout<<0<<"\n";
        }
        else if(n == 2){
            cout<<m<<"\n";
        }
        else{
            cout<<2*m<<"\n";
        }
    }

return 0;
}

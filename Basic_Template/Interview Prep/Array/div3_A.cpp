/*
https://codeforces.com/contest/1324/problem/A
*/
#include<bits/stdc++.h>
using namespace std;


int main(){

    int t;  cin>>t;

    while(t--){
        int n;  cin>>n;

        int p1=0,p2=0,x;

        for(int i=0;i<n;i++){
            cin>>x;
            if(x%2 == 0) p1++;
            else p2++;
        }

        if(p1 == n || p2 == n){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }


return 0;
}

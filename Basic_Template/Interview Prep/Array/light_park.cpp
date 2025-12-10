/*
https://codeforces.com/contest/1358/problem/0
*/
#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;  cin>>t;

    while(t--){
        int n,m;  cin>>n>>m;

        int total = n*m;

        if(total%2 == 0){  /// Even
            cout<<total/2<<endl;
        }
        else{
            int extra = total%2;
            total -= extra;
            cout<<(total/2)+extra<<endl;
        }
    }

return 0;
}

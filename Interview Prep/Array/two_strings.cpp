#include<bits/stdc++.h>
#include<map>
#define ll long long int
using namespace std;


int main(){

    ll t;  cin>>t;


    while(t--){

    string a,b;   cin>>a>>b;
    int n = a.length();

    map<char,int> mp;

    for(int i=0;i<n;i++){
        mp[a[i]] = 0;
    }

    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }

    int n2 = b.length();

    for(int i=0;i<n2;i++){
        if(mp.find(b[i]) != mp.end()){
            mp[b[i]] = 0;
        }
    }

    string nw = "";

    for(int i=0;i<n;i++){
        if(mp[a[i]] > 0){
            nw += a[i];
        }
    }
    cout<<nw<<endl;

    }

return 0;
}

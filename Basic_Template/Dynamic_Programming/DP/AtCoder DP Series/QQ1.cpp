#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;  cin>>t;

    while(t--){
        int n,k;  cin>>n>>k;
        int d;
        string s="";

        while(n--){
          cin>>d;

          if(d%k == 0) s += "1";
          else s += "0";
        }
        cout<<s<<endl;
    }

return 0;
}

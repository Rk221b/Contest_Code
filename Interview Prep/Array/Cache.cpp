#include<bits/stdc++.h>
#include<map>
#include<vector>
#define ll long long int
using namespace std;


int main(){

    ll t;  cin>>t;


    while(t--){
        ll n,b,m;  cin>>n>>b>>m;

        ll ans = 0;

        ll arr[m];

        for(int i=0;i<m;i++){
            cin>>arr[i];
        }

        vector<vector<int> > c;
        int x = 0,tmp = 0;
        vector<int> v;

        while(x<n){
            tmp = 0;
            while(tmp < b){
                v.push_back(x);
                x++;
                tmp++;
            }
            c.push_back(v);
            v.clear();
        }
        int l = 0,r = b-1;
        int i = 0;
        for(;i<m;){

            for(int j=0;j<c.size();j++){
                l = c[j][0];
                r = c[j][c[j].size()-1];
                if(arr[i] >= l && arr[i] <= r){
                    ans++;
                    while(arr[i] >= l && arr[i] <= r){
                        i++;
                    }
                }
            }
          //  cout<<i<<endl;
        }
    cout<<ans<<endl;

    }


return 0;
}

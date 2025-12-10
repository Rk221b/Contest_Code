#include<bits/stdc++.h>
#include<map>
#define ll long long int
using namespace std;


int main(){

    ll t;  cin>>t;


    while(t--){
        ll n,m;  cin>>n>>m;

        ll arr[n];
        map<ll,ll> mp;

        for(ll i=0;i<n;i++){
            cin>>arr[i];
            mp[arr[i]] = 0;
        }

        for(ll i=0;i<n;i++){
            mp[arr[i]]++;
        }

//        sort(arr,arr+n);

            ll a1 = 0,a2=0;
            ll t1 = m-1, t2 = m+1;

            while(mp.find(t1) != mp.end()){
                a1 += mp[t1];
              //  cout<<t1<<" "<<mp[t1]<<endl;
                t1--;
            }

         /*   while(mp.find(t2) != mp.end()){
                ans += mp[t2];
             //   cout<<t2<<" "<<mp[t2]<<endl;
                t2++;
            } */

            for(int i=0;i<n;i++){
                if(arr[i] > m){
                    a2++;
                }
            }

            int f = 0;

            for(int i=1;i<m-1;i++){
                if(mp.find(i) == mp.end()){
                    cout<<-1<<endl;
                    f = 1;
                    break;
                }
            }
            if(f == 0){
                cout<<a1+a2<<endl;
            }

    }


return 0;
}

#include<bits/stdc++.h>
#include<queue>
#define ll long long int
using namespace std;


int main(){

    ll t;  cin>>t;


    while(t--){
        ll n;  cin>>n;
        ll x;

        priority_queue<int> pq;

        for(ll i=0;i<n;i++){
            cin>>x;
            pq.push(x);
        }

        ll ans = 0;
        int tmp = 1;

        while(pq.size() >= 3){
            tmp = 1;
            while(tmp < 3){
                pq.pop();
                tmp++;
            }
            ans += pq.top();
            pq.pop();
        }
        cout<<ans<<endl;
    }


return 0;
}

/*
https://hack.codingblocks.com/app/practice/1/137/problem
*/
#include<bits/stdc++.h>
#include<vector>
#define ll long long int
using namespace std;

vector<ll> primeFactor(ll n){

vector<ll> ans;

for(ll i=2;i*i<=n;i++){
    if(n%i == 0){
        while(n%i == 0)
        n /=i;
    ans.push_back(i);
 //   cout<<"IN fun loop"<<i<<endl;
    }
}
//cout<<"IN fun "<<n<<endl;
if(n > 1){
    ans.push_back(n);
}
return ans;
}

int main(){

ll t;  cin>>t;

while(t--){
    ll n,k;  cin>>n>>k;
   // vector<int> primefacN;
    vector<ll> primefacK;

    primefacK = primeFactor(k);

    ll ans = INT_MAX,p1 = 0,p2=0,c1,c2,d,x;

    for(int i=0;i<primefacK.size();i++){
            p1 = 0, p2 = 0;
            c1 = n;
            c2 = k;
            d = primefacK[i];

            while(d <= c1){
                p1 += floor(c1/d);
                d *= primefacK[i];
            }

            d = primefacK[i];
            while(c2 % d == 0){
                p2++;
                c2 /= d;
            }
            x = floor(p1/p2);

          // cout<<"PRIME "<<primefacK[i]<<endl;
          //  cout<<p1<<" "<<p2<<endl;

            ans = min(ans,x);
    }
    cout<<ans<<endl;
}

return 0;
}

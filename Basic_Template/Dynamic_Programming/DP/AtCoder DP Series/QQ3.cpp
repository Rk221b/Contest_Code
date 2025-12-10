#include<bits/stdc++.h>
#include <stdio.h>
#define ll long long int
using namespace std;

string dB(ll n)
{
    string s = bitset<128> (n).to_string();
    const auto ff = s.find('1');

    if(ff != string::npos)
        return s.substr(ff);

    return "0";
}

ll bD(string n)
{
    string num = n;
    ll val = 0;
    ll b = 1;

    ll len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            val += b;
        b *= 2;
    }

    return val;
}

int main(){

    ll t;  cin>>t;

    while(t--){
        ll n; cin>>n;
        ll arr[n];

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ll x,y;

        ll ans;
        int flag = 0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                x = arr[i];
                y = arr[j];

                string binX = dB(x);
                string binY = dB(y);

                string binXplusY = binX + binY;
                string binYplusX = binY + binX;

                ll XplusY = bD(binXplusY);
                ll YplusX = bD(binYplusX);

                if(flag == 0){
                    ans = XplusY - YplusX;
                    flag = 1;
                }
                else
                    ans = max(ans,XplusY - YplusX);
            }
        }
        cout<<ans<<endl;
    }

return 0;
}

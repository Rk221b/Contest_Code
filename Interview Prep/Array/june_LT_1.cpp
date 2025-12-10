#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

    ll t;   cin>>t;


    while(t--){
        ll s,n;  cin>>s>>n;

        ll ans = 0;

        if(s < n){
            if(s%2 == 0){
                n = s;
            }
            else{
                if(s > 1)
                n = s-1;
            }
        }

        while(s > 0 && n > 0){

            if(s < n){
                if(s%2 == 0){
                    n = s;
                }
            else{
                    if(s > 1)
                    n = s-1;
                }
            }

            if(n == 1 || s == 1){
                ans += s;
              //  cout<<"here "<<s<<endl;
                break;
            }
            ans += (s/n);
           // cout<<s<<" "<<n<<" "<<ans<<endl;
            s =  (s - (s/n)*n);

            if((n-2) > 1)
            n -= 2;
            else
                n = 1;
        }

        cout<<ans<<endl;
    }

return 0;
}

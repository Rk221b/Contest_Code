/*
https://www.codechef.com/NOV15/problems/SMPLSUM
*/
#include<bits/stdc++.h>
#include<vector>
#define ll long long int

using namespace std;

int phi[10000002];
vector<int> smallestPrimeDiv(10000005,0);

int mx = 1e7;

void euler(){

for(int i=1;i<=1e7;i++){
    phi[i] = i;
}

/*
for(ll i=2;i<=1e7;i++){
    if(phi[i] == i){
        phi[i] = i - 1;
        for(ll j = 2*i; j<=1e7;j = j+i){
           phi[j] = (phi[j] * (i - 1)) / i;
        }
    }
}
*/

for(int i=2; i<=1e7; i++){
    if(phi[i]==i){
        for(int j=i; j<=1e7; j+=i){
            phi[j]-=phi[j]/i;
        }
    }
}

	for(int i =2; i <= mx; i++){
        if(smallestPrimeDiv[i] == 0){
            for(int j =1; j <= mx/i; j++){
                smallestPrimeDiv[i*j] =i;
            }
        }
	}

/*
for(ll i=1;i<=10000000;i++){
    for (ll j = i; j <= 10000000; j += i ) {
        res[j] += ( i * phi[i] );
    }
 }
*/
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  euler();

 int t;  cin>>t;

 vector<int> allFactors;

 while(t--){

    int n;  cin>>n;

    allFactors.clear();

    allFactors.push_back(1);

    int x = n;
    ll ans = 0;
    int cnt = 0;

    while(x>1){

        int sp = smallestPrimeDiv[x];  /// sp is smallest prime which divides x (i.e n)
        cnt=0;
        while(smallestPrimeDiv[x] == sp){  /// while its being divided
            cnt++;
            x /= sp;
        }

        /// Now we will compute all factors of x using sp and its power
        int sz = allFactors.size();

        for(int i=0; i<sz; i++){
            int new_p=1;
            for(int j=1; j<=cnt; j++){
                new_p *= sp;
                allFactors.push_back(allFactors[i]*new_p);
               }
            }
        }

        /// now we have all divisors of n in allFactors vector

        for(auto i : allFactors){
          //  cout<<"Factor "<<i<<" phi value "<<phi[i]<<endl;
            ans += 1LL*phi[i]*i;
        }
    cout<<ans<<"\n";
 }


return 0;
}

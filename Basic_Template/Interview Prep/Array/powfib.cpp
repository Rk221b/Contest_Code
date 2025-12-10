/*
https://www.spoj.com/problems/POWFIB/
*/
#include<bits/stdc++.h>
#include<vector>
#define ll long long int
#define mod 1000000007
using namespace std;

ll nonFibonacci(int n)
{
    int prevPrev=1, prev=2, curr=3;

    while (n > 0)
    {
        prevPrev = prev;
        prev = curr;
        curr = (prevPrev + prev);

        n = n - (curr - prev - 1);
    }

    n = (n + (curr - prev - 1));

    return (prev + n);
}

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B){

    vector<vector<ll>> C(2,vector<ll>(2));

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            C[i][j] = 0;
            for(int x=0;x<2;x++){
                C[i][j] = (C[i][j] + (A[i][x]%mod * B[x][j]%mod)%mod)%mod;
            }
        }
    }
    return C;
}

vector<vector<ll>> power(vector<vector<ll>> T, int p){

    if(p == 0 || p == 1){
        return T;
    }

    if(p & 1){ /// odd power
        return multiply(T, power(T, p-1));
    }
    else{  /// Even Case
        vector<vector<ll>> X = power(T, p/2);

        return multiply(X,X);
    }
}

ll fibo(int n){

vector<vector<ll>> T(2,vector<ll>(2));

T[0][0] = 0;
T[0][1] = 1;
T[1][0] = 1;
T[1][1] = 1;

/*  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        cout<<T[i][j]<<" ";
    }
    cout<<endl;
}  */

T = power(T,n-1);

return T[1][1];

}

ll modpow(ll a, ll b, int m){

if(b == 1){
    return a;
}

ll res = 1;

a = a%m;

  while(b > 0){

    if(b & 1){
        res = (res * a)%m;
    }

    b = b >> 1;
    a = (a*a)%m;
  }
return res;
}

int main(){

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

int t;  //cin>>t;
scanf("%d",&t);

while(t--){

    int n;  //cin>>n;
    scanf("%d", &n);

    int a = nonFibonacci(n);
    int b = fibo(n)%mod;

  //  cout<<"FIBO "<<a<<" NON FIBO "<<b<<endl;

    ll ans = modpow(a,b,mod);

    //cout<<ans<<"\n";
    printf("%lld \n",ans);
}

return 0;
}

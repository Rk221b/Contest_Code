/*
https://www.spoj.com/problems/SEQ/
*/
#include<bits/stdc++.h>
#include<vector>
#define ll long long int
#define mod 1000000000

using namespace std;

ll k;

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B){

/// C = A * B
vector<vector<ll>> C(k , vector<ll>(k));

for(int i=0;i<k;i++){
    for(int j=0;j<k;j++){
        for(int m=0;m<k;m++){
            C[i][j] = (C[i][j] + (A[i][m] * B[m][j])%mod)%mod;
        }
    }
}
    return C;
}

vector<vector<ll>> power(vector<vector<ll>> T, ll p){

    if(p == 1){
        return T;
    }
    if(p & 1){  /// odd case
        return multiply(T,power(T,p - 1));
    }
    else{  /// Even Case
        vector<vector<ll>> X = power(T, p/2);

        return multiply(X,X);
    }
}


int main(){

ll t;  cin>>t;

while(t--){

    cin>>k;

    ll b[k], c[k];

    for(int i=0;i<k;i++){
        cin>>b[i];
    }

    for(int i=0;i<k;i++){
        cin>>c[i];
    }

    ll n;  cin>>n;

    if(n <= k){
        cout<<b[n-1]<<endl;
    }
    else{
        ll F0[k];

        for(int i=0;i<k;i++){
            F0[i] = b[i];
        }

        /// Transformation matrix
        vector<vector<ll>> T(k, vector<ll>(k));

        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(j == i+1){
                    T[i][j] = 1;
                }
                else{
                    T[i][j] = 0;
                }
            }
        }
        int tmp = 0;
        for(int i=k-1;i>=0;i--){
            T[k-1][i] = c[tmp];
            tmp++;
        }

       /*   cout<<"Transformation matrix "<<endl;
          for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
               cout<<T[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"***********"<<endl;  */

        T = power(T,n-1);

        ll answer = 0;

        for(int i=0;i<k;i++){
            answer = (answer + (T[0][i] * F0[i])%mod)%mod;
        }

        cout<<answer<<endl;
    }
}
return 0;
}

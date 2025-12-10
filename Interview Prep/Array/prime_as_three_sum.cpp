/*
https://codeforces.com/problemset/problem/17/A
*/
#include<bits/stdc++.h>
#include<vector>
#define ll long long int

using namespace std;

int prime[1005];
vector<int> onlyPrime;
int kSum[1005];

void sieve(){

 memset(prime,0,sizeof(prime)); /// set all number as prime

 for(int i=2;i<=1000;i++){

    if(prime[i] == 0){
        for(int j=i*i; j<=1000;j+=i){
            prime[j] = 1;  /// set multiple as not prime
        }
        onlyPrime.push_back(i);
    }
  }
  prime[0] = prime[1] = 1;
}

void kValue(){

 memset(kSum,0,sizeof(kSum));
 int s = 0;
 for(int i=0;i<onlyPrime.size() - 1;i++){
    s = onlyPrime[i] + onlyPrime[i+1] + 1;

    if(prime[s] == 0){
        kSum[s]++;
    }
 }

 for(int i=1;i<=1000;i++){
    kSum[i] = kSum[i] + kSum[i-1];
 }
}

int main(){


 ll n,k;  cin>>n>>k;

 sieve();
 kValue();

 /*for(int i=0;i<=100;i++){
    cout<<onlyPrime[i]<<" ";
 }
cout<<endl; */


 if(kSum[n] >= k){
    cout<<"YES"<<endl;
 }
 else{
    cout<<"NO"<<endl;
 }

return 0;
}

#include<bits/stdc++.h>

using namespace std;

void multiply(int A[][2], int B[][2]){

/// C = A * B
int C[2][2];

for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        C[i][j] = 0;

        for(int k=0;k<2;k++){
            C[i][j] += (A[i][k] * B[k][j]);
        }
    }
}

for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        A[i][j] = C[i][j];
    }
}

}

void power(int T[][2], int n){

if(n == 0 || n == 1){
    return;
}

power(T,n/2);

multiply(T,T);

if(n%2 != 0){
    int F[2][2] = {{0,1},{1,1}};
    multiply(T,F);
}
}

int fibo(int n){

if(n == 0 || n == 1){
    return n;
}

 int T[2][2] = {{0,1},{1,1}};

 power(T,n-1);

 return T[1][1];
}


int main(){

int n;  cin>>n;

//for(int i=0;i<10;i++)
cout<<fibo(n)<<endl;

return 0;
}

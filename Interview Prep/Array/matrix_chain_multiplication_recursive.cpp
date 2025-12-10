#include<bits/stdc++.h>
using namespace std;

int matixChain(int matrix[], int i, int j){

if(i >= j){
    return 0;
}

int ans = INT_MAX;

for(int k=i;k<j;k++){
    int temp = matixChain(matrix,i,k) + matixChain(matrix,k+1,j) + matrix[i-1]*matrix[k]*matrix[j];
    ans = min(ans,temp);
}

return ans;
}

int main(){

int matrix[] = {1,2,3,4};   /// Denotes 3 matrices A,B,C for dimensions 1*2, 2*3, 3*4

int n = sizeof(matrix)/sizeof(matrix[0]);

int i = 1;   /// i and j denotes the point where we can break our matrices
int j = n-1; ///  example   A | BCD,  AB | CD,   ABC | D

cout<<matixChain(matrix,i,j)<<endl;

return 0;
}

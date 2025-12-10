#include<bits/stdc++.h>
using namespace std;
long long A,B,C;
int dp[32][32][32][2];
int add(int i,int a,int b,int c)
{
    return (a+b+c)%2;
}
int carry(int i,int a,int b,int c)
{
    return (a+b+c)/2;
}
long helper(int i,int nA,int nB,int c)
{
    int k = 0;
    if(nA<0 || nB<0)
        return 0;
    if(i==32)
        return (nA==0&&nB==0&&c==0);
    if(1LL<<i & C)
        k = 1;
    int &sol = dp[i][nA][nB][c];
    if(sol!=-1)
        return sol;
    sol = 0;
    if(add(i,0,0,c)==k)
        sol += helper(i+1,nA,nB,carry(i,0,0,c));
    if(add(i,0,1,c)==k)
        sol += helper(i+1,nA,nB-1,carry(i,0,1,c));
    if(add(i,1,0,c)==k)
        sol += helper(i+1,nA-1,nB,carry(i,1,0,c));
    if(add(i,1,1,c)==k)
        sol += helper(i+1,nA-1,nB-1,carry(i,1,1,c));
    return sol;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>A>>B>>C;
        memset(dp,-1,sizeof(dp));
        int nA = 0;
        int nB = 0;
        for(int i=0;i<32;i++)
        {
            if(A & (1LL<<i))
                nA++;
            if(B & (1LL<<i))
                nB++;
        }
        cout<<helper(0,nA,nB,0)<<endl;
    }
}

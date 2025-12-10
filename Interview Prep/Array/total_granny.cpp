/*
https://codeforces.com/contest/1358/problem/B
*/
#include<bits/stdc++.h>
#include<queue>
#include<map>

using namespace std;

int main(){

    int t;  cin>>t;

    while(t--){
        int n;  cin>>n;
        int arr[n];

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr,arr+n);
        int ans = 1;
        int cn = n;

        for(int i=n-1;i>=0;i--){
            if(arr[i] <= cn){
                ans += cn;
                break;
            }
            else{
                cn--;
            }
        }


       cout<<ans<<endl;
    }

return 0;
}

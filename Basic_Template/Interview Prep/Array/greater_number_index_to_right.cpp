/*
https://codeforces.com/problemset/gymProblem/101343/H
*/

#include<bits/stdc++.h>
#include<stack>
#define ll long long int
using namespace std;

int main(){

    int t;
    t = 1;

    while(t--){
        ll n;  cin>>n;
        ll arr[n];
        stack<pair<int,int>> st;

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }


        ll res[n];

        for(int i=0;i<n;i++){
            res[i] = -1;
        }

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i] > arr[st.top().second]){
                res[st.top().second] = arr[i];
                st.pop();
            }
            st.push(make_pair(arr[i],i));
        }

        while(!st.empty()){
            res[st.top().second] = -1;
            st.pop();
        }

        for(int i=0;i<n;i++){
           cout<<res[i]<<" ";
        }
    }

return 0;
}

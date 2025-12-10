/*
https://codeforces.com/problemset/gymProblem/101343/H
Author: Ritik Kapoor
*/
#include<bits/stdc++.h>
#include<stack>
#include<vector>
#define ll long long int
using namespace std;

bool compare(pair<int,int> A, pair<int,int> B){
  return A.first < B.first;
}

int main(){

    ll n;  cin>>n;
    ll arr[n];
    stack<pair<int,int>> st;
    vector<pair<int,int>> ans;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
            while(!st.empty() && st.top().second < arr[i]){
                //cout<<arr[i]<<" ";
                ans.push_back(make_pair(st.top().first,arr[i]));
                st.pop();
            }
            st.push(make_pair(i,arr[i]));
    }

    while(!st.empty()){
       // cout<<-1<<" ";
       pair<int,int> tmp = st.top();
       tmp.second = -1;
       ans.push_back(tmp);
       st.pop();
    }

    sort(ans.begin(), ans.end(), compare);

    for(auto ele: ans){
        cout<<ele.second<<" ";
    }

return 0;
}

#include<bits/stdc++.h>
#include<queue>
using namespace std;


int main(){

int n;  cin>>n;
int arr[n];

for(int i=0;i<n;i++){
    cin>>arr[i];
}

int k;  cin>>k;

priority_queue <pair<int,int>> Q;

/// process first k elements
int i = 0;
for(;i<k;i++){
    Q.push(make_pair(arr[i],i));
}

cout<<Q.top().first<<" ";

for(;i<n;i++){
    while(!Q.empty() && Q.top().second <= i-k){
        Q.pop();
    }
    Q.push(make_pair(arr[i],i));

    cout<<Q.top().first<<" ";
}

return 0;
}

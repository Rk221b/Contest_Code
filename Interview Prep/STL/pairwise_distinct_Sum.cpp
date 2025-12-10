/*
https://www.codechef.com/LRNDSA03/problems/DPAIRS
Author = Ritik Kapoor
 */
#include<bits/stdc++.h>
#include<vector>
using namespace std;


int main(){

int n,m;  cin>>n>>m;

vector<pair<int,int>> a(n);
vector<pair<int,int>> b(m);

int tmp;

for(int i=0;i<n;i++){
    cin>>tmp;
    a[i] = make_pair(tmp,i);
}

for(int i=0;i<m;i++){
    cin>>tmp;
    b[i] = make_pair(tmp,i);
}

sort(a.begin(),a.end());
sort(b.begin(),b.end(), greater<pair<int,int>>());

/*
cout<<endl;
for(int i=0;i<n;i++){
    cout<<a[i].first<<" ";
}
cout<<endl;
for(int i=0;i<m;i++){
    cout<<b[i].first<<" ";
}
cout<<endl;
*/
int mx1 = a[n-1].second;
int mx2 = b[m-1].second;
int ct = 0;

for(int i=0;i<m;i++){
    cout<<mx1<<" "<<b[i].second<<endl;
}
for(int i=0;i<n;i++){
    if(a[i].second != mx1)
    cout<<a[i].second<<" "<<mx2<<endl;
}

return 0;
}

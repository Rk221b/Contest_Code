#include<iostream>
#include<map>
#include<cstring>

using namespace std;


int main(){

multimap<char,string> m;

int n;  cin>>n;
char a; string s;

for(int i=0;i<n;i++){
    cin>>a>>s;
    m.insert(make_pair(a,s));
}

for(auto p:m){
    cout<<p.first<<"->"<<p.second<<endl;
}
cout<<endl;


return 0;
}

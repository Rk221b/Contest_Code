/*
https://codeforces.com/problemset/problem/1187/C
Author: Ritik Kapoor
*/
#include<bits/stdc++.h>
using namespace std;

int main(){

int n,m;  cin>>n>>m;

int sl,sr,ul,ur,type,l,r,f1=0,f2=0;

while(m--){
    cin>>type>>l>>r;
    if(type == 1){
        if(f1 == 0){
            sl = l;
            sr = r;
            f1 = 1;
        }
        else{
            if(l < sl){
                sl = l;
            }
            if(r > sr){
                sr = r;
            }
        }
    }

    if(type == 0){
        if(f2 == 0){
            ul = l;
            ur = r;
            f2 = 1;
        }
        else{
            if(l < ul){
                ul = l;
            }
            if(r > ur){
                ur = r;
            }
        }
    }
}
cout<<sl<<" "<<sr<<" "<<ul<<" "<<ur<<endl;
if((ul >= sl && ul <= sr) || (ur >= sl && ur <= sr)){
    cout<<"NO"<<endl;
}
else{
    cout<<"YES"<<endl;
}

return 0;
}

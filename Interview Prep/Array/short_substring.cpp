#include<bits/stdc++.h>
using namespace std;


int main(){

    int t;  cin>>t;

    while(t--){
        string s;   cin>>s;

        int len = s.length();


        for(int i=0;i<len;i+=2){
            cout<<s[i];
        }
        cout<<s[len-1]<<endl;
    }


return 0;
}

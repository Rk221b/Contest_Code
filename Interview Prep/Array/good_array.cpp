#include<bits/stdc++.h>
using namespace std;


int main(){

    int t;  cin>>t;

    while(t--){
        int n;  cin>>n;

        int arr[n];
        int p1=0,p2=0;

        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i%2 ==0 &&arr[i]%2 != 0) p1++;
            else if(i%2 ==1 &&arr[i]%2 != 1)p2++;
        }
        if(p1 != p2){
            cout<<-1<<"\n";
        }
        else{
            cout<<p1<<"\n";
        }
    }


return 0;
}


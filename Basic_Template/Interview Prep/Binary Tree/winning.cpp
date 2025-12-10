#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main(){

    int t;  cin>>t;


    while(t--){

        int n;  cin>>n;
        ll arr[n];

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr,arr+n);
        reverse(arr,arr+n);

        ll a1 = 0, a2 = 0;
        int f = 0, i = 0,f1 = 0;
        for(;i<n;){
            if(f == 0){
                a1 += arr[i];
                f = 1;
                i++;
            }
            else{
                if(f1 == 0){
                    a2 += arr[i];
                    i++;
                    if(i < n){
                        a2 += arr[i];
                        i++;
                    }
                    f = 0;
                    f1 = 1;
                }
                else{
                    a2 += arr[i];
                    i++;
                    f = 0;
                }
            }
        }

        cout<<"S "<<a1<<" "<<a2<<endl;
        if(a1 > a2){
            cout<<"first"<<endl;
        }
        else if(a1 < a2){
            cout<<"second"<<endl;
        }
        else{
            cout<<"draw"<<endl;
        }
    }

return 0;
}

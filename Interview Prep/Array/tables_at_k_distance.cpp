#include<bits/stdc++.h>
using namespace std;


int main(){

    int t;  cin>>t;

    while(t--){
        int n,k;  cin>>n>>k;

        string s;  cin>>s;

        int ans = 0;
       // int len = s.length();

        int arr[n];

        for(int i=0;i<n;i++){
            if(s[i] == '0') arr[i] = 0;
            else arr[i] = 1;
        }

        int pre[n+1];
        int suf[n+1];

        memset(pre,-1,sizeof(pre));
        memset(suf,-1,sizeof(suf));

        if(arr[0] == 1){
            pre[0] = 0;
        }

        for(int i=1;i<n;i++){
            if(arr[i] == 1){
                pre[i] = i;
            }
            else{
                pre[i] = pre[i-1];
            }
        }

        if(arr[n-1] == 1){
            suf[n-1] = n-1;
        }

        for(int i=n-2;i>=0;i--){
            if(arr[i] == 1){
                suf[i] = i;
            }
            else{
                suf[i] = suf[i+1];
            }
        }

        /*
        for(int i=0;i<n;i++){
            cout<<pre[i]<<" ";
        }
        cout<<endl;

        for(int i=n-1;i>=0;i--){
            cout<<suf[i]<<" ";
        }
        cout<<endl;  */

        int val1,val2;

        for(int i=0;i<n;i++){
            if(arr[i] == 0){
                val1 = val2 = INT_MAX;
                if (pre[i] != -1) {
                    val1 = i - pre[i];
                }
                if (suf[i] != -1) {
                    val2 = suf[i] - i;
                }

                if (min(val1, val2) > k) {
                    ans++;
                    pre[i] = i;
                }
                if(pre[i+1] < pre[i]){
                    pre[i+1] = pre[i];
                }
            }
           // cout<<pre[i]<<" "<<suf[i]<<endl;
        }

        cout<<ans<<endl;

        }
return 0;
}



#include<bits/stdc++.h>
using namespace std;



int main(){

    int t;  cin>>t;
    int test = 1;

    while(t--){

        int n; cin>>n;

        vector<int> arr(n,0);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int ans = 0, diff = 0;

        for(int i=0;i<n-1;i++){
            diff = abs(arr[i] - arr[i+1]);
            ans = max(ans,diff);
        }

        cout<<"Case #"<<test<<": "<<ans<<endl;
        test++;
    }

return 0;
}

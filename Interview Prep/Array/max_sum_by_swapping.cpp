#include<bits/stdc++.h>
#include<vector>

using namespace std;


int main(){

    int t;  cin>>t;

    while(t--){

        int n,k;  cin>>n>>k;
        vector<int> a(n);
        vector<int> b(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());


        int tmp = n-1;
        int ans = 0;

        for(int i=0;i<n;i++){
            if(a[i] < b[tmp] && k > 0 && tmp >=0){
                ans += b[tmp];
                tmp--;
                k--;
            }
            else{
                ans += a[i];
            }
        }
        cout<<ans<<"\n";
    }

return 0;
}

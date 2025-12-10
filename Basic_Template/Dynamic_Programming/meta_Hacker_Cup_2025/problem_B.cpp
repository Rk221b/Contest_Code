#include<bits/stdc++.h>
using namespace std;


bool canClimbe(vector<int> &arr, int ladder, int n){

    vector<int> visited(n,-1);

    for(int i=0;i<n;i++){

        if(visited[i] == -1 && arr[i] <= ladder){

            visited[i] = 1;
            /// go left till you can
            int idx = i;

            while((idx-1) >= 0 && abs(arr[idx]-arr[idx-1]) <= ladder){
                visited[idx-1] = 1;
                idx--;
            }


            /// go right till you can
            idx = i;

            while((idx+1) < n && abs(arr[idx]-arr[idx+1]) <= ladder){
                visited[idx+1] = 1;
                idx++;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(visited[i] == -1) return false;
    }

    return true;
}


int main(){

    int t;  cin>>t;
    int test = 1;

    while(t--){

        int n; cin>>n;

        vector<int> arr(n,0);
        int mx = 0, mn = INT_MAX;

        for(int i=0;i<n;i++){
            cin>>arr[i];
            mx = max(mx, arr[i]);
            mn = min(mn, arr[i]);
        }

        int ans = 0, diff = 0, mid = 0;

        while(mn <= mx){

            mid = (mx+mn)/2;

            if(canClimbe(arr,mid,n)){
                ans = mid;
                mx = mid-1;
            }
            else{
                mn = mid+1;
            }

        }

        cout<<"Case #"<<test<<": "<<ans<<endl;
        test++;
    }

return 0;
}

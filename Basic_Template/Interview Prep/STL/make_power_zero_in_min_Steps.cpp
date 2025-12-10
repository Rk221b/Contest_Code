#include<bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;


int main(){

int t; cin>>t;

while(t--){
    int n,z;  cin>>n>>z;
    int tmp;
    priority_queue<int> soldier;
    int ans = 0;

    for(int i=0;i<n;i++){
        cin>>tmp;
        soldier.push(tmp);
    }
    int mx;
    while(z > 0 && !soldier.empty()){
        mx = soldier.top();
     //   cout<<"Z "<<z<<" power soldier "<<mx<<endl;
        soldier.pop();
        z = z - mx;
        mx /= 2;
        if(mx > 0)
            soldier.push(mx);

        ans++;
    }

    if(z <= 0){
        cout<<ans<<endl;
    }
    else{
        cout<<"Evacuate"<<endl;
    }
}

return 0;
}

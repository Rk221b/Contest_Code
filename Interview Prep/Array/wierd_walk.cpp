#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int

using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
        int n;  cin>>n;

        int a[n],b[n];
        ll ans = 0;
        ll d1[n],d2[n];

        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i == 0){
                d1[i] = a[i];
            }
            else{
                d1[i] = d1[i-1] + a[i];
            }
        }

        for(int i=0;i<n;i++){
            cin>>b[i];

            if(i == 0){
                d2[i] = b[i];
            }
            else{
                d2[i] = d2[i-1] + b[i];
            }
        }

        for(int i=0;i<n;i++){
            if(d1[i] == d2[i]){
                if(i == 0){
                    ans += d1[i];
                }
                else{
                    if(d1[i-1] == d2[i-1]){
                        ans += d1[i] - d1[i-1];
                    }
                }
            }
        }

        cout<<ans<<endl;
	}
	return 0;
}

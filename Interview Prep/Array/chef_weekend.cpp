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
        int a[5];
        int p;
        ll total = 0;

        for(int i=0;i<5;i++){
            cin>>a[i];
        }
        cin>>p;

        for(int i=0;i<5;i++){
            total += a[i]*p;
        }
       // cout<<total<<endl;
        if(total <= 120)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
	}
	return 0;
}

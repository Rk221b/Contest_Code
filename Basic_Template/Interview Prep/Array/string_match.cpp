#include <bits/stdc++.h>
#include<map>

using namespace std;
int main()
{

	int T;
	cin>>T;
	while(T--)
	{
      string s;  cin>>s;

      int n = s.length();

      int ans = 0;

      for(int i=2;i<n;i+=2){

            string t1 = s.substr(0,(i/2));
            string t2 = s.substr(i/2,(i/2));
            string t3 = s.substr(i,((n-i)/2));
            string t4 = s.substr(i+((n-i)/2));

         //   cout<<"1 "<<t1<<" 2 "<<t2<<" 3 "<<t3<<" 4 "<<t4<<endl;

            if(t1 == t2 && t3 == t4){
                ans++;
            }
      }
      cout<<ans<<"\n";
	}
	return 0;
}

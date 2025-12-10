#include <bits/stdc++.h>
#include<map>

using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
        int n;  cin>>n;

        int arr[n];

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        map<int,bool> ct;
        map<int,bool> uniq;

        int flag = 0;
        int i = 0,j=0;

        for(;i<n;i++){
            int value = 1;
          //  cout<<"EL "<<arr[i]<<endl;
            if(arr[i] == arr[i+1] && i+1 < n){
             //   cout<<"HERE"<<endl;
                j = i;
                while(arr[i] == arr[j+1] && j+1 < n){
                    j++;
                    value++;
               //     cout<<" INC J "<<j<<endl;
                }
              //  cout<<"VALUE "<<value<<endl;
                if((uniq.find(arr[i]) != uniq.end()) || (ct[value] == true)){
                    flag = 1;
                    break;
                }
                else{
                    uniq[arr[i]] = true;
                    ct[value] = true;
                }
                i = j;
          //      cout<<"NEW I "<<i<<endl;
            }
            else{
                if((uniq.find(arr[i]) != uniq.end()) || (ct[value] == true)){
                    flag = 1;
                    break;
                }
                else{
                    uniq[arr[i]] = true;
                    ct[value] = true;
                }
            }
            if(flag == 1){
                break;
            }
        }

        if(flag == 1){
            cout<<"NO"<<"\n";
        }
        else{
            cout<<"YES"<<"\n";
        }

	}
	return 0;
}

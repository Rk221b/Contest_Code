#include <bits/stdc++.h>
#include<map>
using namespace std;

int matrixMul(int arr[], int i, int j){

    if(i > j){
        return 0;
    }

    int ans = INT_MIN;

    for(int k=i;k<j;k++){
        int temp = matrixMul(arr,i,k) + matrixMul(arr,k+1,j) + (arr[i] + arr[j]);

        ans = max(ans,temp);
    }
return ans;
}

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

      int ans = matrixMul(arr,0,n-1);

      cout<<ans<<"\n";

	}
	return 0;
}

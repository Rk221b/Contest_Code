/*
You are given number of pages in n different books and m students. The books are arranged in ascending order of number of pages.
Every student is assigned to read some consecutive books.
The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.
*/

#include<bits/stdc++.h>
using namespace std;

bool canRead(int books[], int n, int m, int pages){

    int students = 1;
    int max_can_read = 0;

    for(int i=0;i<n;i++){
        if((max_can_read+books[i]) <= pages){
            max_can_read += books[i];
        }
        else{
            students++;
            max_can_read = books[i];
        }
        if(students > m){
            return false;
        }
    }
    return true;
}

int main(){

    int t;  cin>>t;

    while(t--){

		int n,m;  cin>>n>>m;
		int books[n];
		int sum = 0;

		for(int i=0;i<n;i++){
			cin>>books[i];
			sum += books[i];
		}

		int s = books[n-1], e = sum;
		int ans = e;

		while(s <= e){
			int mid = (s+e)/2;

			if(canRead(books,n,m,mid) == true){
				ans = mid;
				e = mid - 1;
			//   cout<<"ANS "<<ans<<endl;
			}
			else{
				s = mid + 1;
			}
		}

		cout<<ans<<"\n";
    }

return 0;
}

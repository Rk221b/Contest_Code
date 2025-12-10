#include<bits/stdc++.h>
#include<deque>

using namespace std;


int main(){

   int n;   cin>>n;
   int arr[n];

   for(int i=0;i<n;i++){
    cin>>arr[i];
   }

   int k;   cin>>k;

   deque<int> q(k);   /// to store index of elements

   int i = 0;

   for(;i<k;i++){

     while(!q.empty() && arr[i] >= arr[q.back()]){  /// Aim is to keep largest element at front of deque
        q.pop_back();
     }
     q.push_back(i);
   }
   /// Max element among first k will be in front of q.

   for(;i<n;i++){
    cout<<arr[q.front()]<<" ";

    /// 1. Check for expired index that are not longer part of out window (Contraction part)

    while(!q.empty() && q.front() <= i-k){
        q.pop_front();
    }

    ///2. Keep relevant elements only

    while(!q.empty() && arr[i] >= arr[q.back()]){  /// Aim is to keep largest element at front of deque
        q.pop_back();
     }

    q.push_back(i);
   }

   cout<<arr[q.front()]<<" "; /// For last window

return 0;
}

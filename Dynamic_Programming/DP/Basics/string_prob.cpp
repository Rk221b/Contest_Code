// aaaaabbbccc

#include<bits/stdc++.h>
using namespace std;


int main(){

 // arr array as

 string arr[] = {"a","a","a","a","b","b","c","c","c","d","d"};

// a b 2 @

 int ct = 0, flag = 0,f2=0;
 int i = 0;
 int len = 11;//arr.length();

 for(;i<len;i++){
        ct = 1;
    for(int j=i+1;j<len;j++){
        if(arr[i] == arr[j]){
            ct++;
            if(ct >= 2){
                arr[j] = "@";
            }
        }
        else{

            if(ct > 1){
                arr[i+1] = to_string(ct);
            }
            i = j-1;
            cout<<i<<" "<<j<<endl;
            break;
        }
        if(j == len-1){
        arr[len-1] = to_string(ct);
    }
    }
 //   cout<<i<<" ";
 }
// cout<<endl;

 for(int k=0;k<len;k++){
    cout<<arr[k]<<" ";
 }
 cout<<endl;

return 0;
}

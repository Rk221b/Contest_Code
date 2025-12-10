/*
https://leetcode.com/problems/palindrome-partitioning-ii/
*/
#include<bits/stdc++.h>
#include<vector>

using namespace std;

bool is_palindrome(string s, int l, int r){

  while(l <= r){

        if(s[l] != s[r]){
            return false;
        }
            l++;
            r--;
   }
return true;
}

int find_all_partitions(string s, int i , int j){

    /// Base Case
    if(i >= j){
        return 0;
    }

    if(is_palindrome(s,i,j)){
        return 0;
    }

    int ans = INT_MAX;

    for(int k=i;k<j;k++){
        int op = 1 + find_all_partitions(s,i,k) + find_all_partitions(s,k+1,j);

        ans = min(ans,op);
    }
    return ans;
}

int main(){

string s;  cin>>s;

int ans = find_all_partitions(s,0,s.length()-1);

cout<<ans<<endl;

return 0;
}

/*
https://leetcode.com/problems/palindrome-partitioning/
*/
#include<bits/stdc++.h>
#include<vector>

using namespace std;

vector<string> ans;
vector<vector<string>> finalAns;

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

void find_all_partitions(string s, int pos , string res){

    if(pos == s.length()){
        //cout<<res<<endl;
        finalAns.push_back(ans);
        return;
    }

    string temp = "";

    for(int i=pos;i<s.length();i++){
      //  temp += s[i];
        if(is_palindrome(s,pos,i) == true){

            ans.push_back(s.substr(pos, i-pos+1));

            find_all_partitions(s,i+1, res+"|"+temp);

            ans.pop_back();
        }
    }
}

int main(){

string s;  cin>>s;

find_all_partitions(s,0,"");

for(auto i:finalAns){
    for(auto j: i){
        cout<<j<<",";
    }
    cout<<endl;
}

return 0;
}

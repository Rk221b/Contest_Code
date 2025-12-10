#include<bits/stdc++.h>
#define MAX 3000
using namespace std;

int dp[MAX+1][MAX+1];

string print_lcs(string& s, string& t, int len){

    string LCS = "";
    int i=0,j=0;

    while(len > 0){
        if(s[i] == t[j]){
            LCS += s[i];
            i++;
            j++;
            len--;
        }
        else{
            if(dp[i][j+1] > dp[i+1][j]){
                j++;
            }
            else{
                i++;
            }
        }
    }
    return LCS;
}

int length_lcs(string& s, string& t, int i, int j){

    if(i >= s.length() || j >= t.length()){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(s[i] == t[j]){
        return dp[i][j] = 1 + length_lcs(s,t,i+1,j+1);  /// here dp[i][j] represents length of lcs of string s from i to end and string t from j to end
    }
    else{
        return dp[i][j] = max(length_lcs(s,t,i+1,j),length_lcs(s,t,i,j+1));
    }
}

int main(){

    string s,t;  cin>>s>>t;

    memset(dp,-1,sizeof(dp));

    int len = length_lcs(s,t,0,0);

    string LCS;

    LCS = print_lcs(s,t,len);

    cout<<LCS<<"\n";

return 0;
}

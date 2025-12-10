#include<bits/stdc++.h>
#include<stack>
using namespace std;


void scoreOfParentheses(string &S) {
        int i, n = (int)S.size();
        vector<int> en;
        n = max(n, 1);
        en.resize(n, 0);
        stack<int> s;
        for(i=0; i<n; i++){
            if(S[i] == ')'){
                int t = s.top();
                en[t] = i;
                s.pop();
            }
            else s.push(i);
        }

        for(int j=0;j<en.size();j++){
            cout<<en[j]<<" ";
        }
        cout<<endl;
      //  return go(0, n-1);
}

int main(){

string s;  cin>>s;


scoreOfParentheses(s);

return 0;
}

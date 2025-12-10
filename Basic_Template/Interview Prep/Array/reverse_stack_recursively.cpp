#include<bits/stdc++.h>
#include<stack>

using namespace std;

void insertAtEnd(stack<int> &s, int x){

    if(s.empty()){
        s.push(x);
        return;
    }

    int y = s.top();
    s.pop();

    insertAtEnd(s,x);

    s.push(y);

}

void reverseStackRecursive(stack<int> &s){

    if(s.empty()){
        return;
    }

    int x = s.top();
    s.pop();

    reverseStackRecursive(s);

    insertAtEnd(s,x);

}

int main(){

    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverseStackRecursive(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

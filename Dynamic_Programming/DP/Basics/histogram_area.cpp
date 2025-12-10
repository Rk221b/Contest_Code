#include<bits/stdc++.h>
#include<stack>
using namespace std;

void nextSmallerToLeft(vector<int> &nearest_smaller_left, int heights[], int n){

     /// maintain ascending order in stack
    stack<int> st;

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && heights[i] < heights[st.top()]){
            nearest_smaller_left[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        nearest_smaller_left[st.top()] = -1;
        st.pop();
    }
}


void nextSmallerToRight(vector<int> &nearest_smaller_right, int heights[], int n){

    /// maintain ascending order in stack
    stack<int> st;

    for(int i=0;i<n;i++){
        while(!st.empty() && heights[i] < heights[st.top()]){
            nearest_smaller_right[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        nearest_smaller_right[st.top()] = n;
        st.pop();
    }
}

int main(){

int n;  cin>>n;
int heights[n];

for(int i=0;i<n;i++){
    cin>>heights[i];
}

vector<int> nearest_smaller_left(n);
vector<int> nearest_smaller_right(n);

nextSmallerToRight(nearest_smaller_right,heights,n);
nextSmallerToLeft(nearest_smaller_left,heights,n);


cout<<"Smaller element to Right "<<endl;

for(auto i: nearest_smaller_right){
    if(i == n)
        cout<<-1<<" ";
    else
        cout<<heights[i]<<" ";
}
cout<<endl;


cout<<"Smaller element to Left "<<endl;

for(auto i: nearest_smaller_left){
    if(i == -1)
        cout<<i<<" ";
    else
        cout<<heights[i]<<" ";
}
cout<<endl;

int ans = 0;

for(int i=0;i<n;i++){
    ans = max(ans, (nearest_smaller_right[i] - nearest_smaller_left[i] - 1) * heights[i]);
}

cout<<ans<<endl;

return 0;
}

#include<bits/stdc++.h>
#define Mod 1000000007

using namespace std;

int memo_recursive(int curr_row, int curr_col, int tot_row, int tot_col, vector<vector<char>>& grid, vector<vector<int>>& dp){

    /// Base case
    if(curr_row == tot_row-1 && curr_col == tot_col-1) return 1;
    if(curr_row >= tot_row || curr_col >= tot_col || curr_row < 0 || curr_col < 0 || grid[curr_row][curr_col] == '#') return 0;

    /// DP check
    if(dp[curr_row][curr_col] != -1) return dp[curr_row][curr_col];

    int right = memo_recursive(curr_row,curr_col+1,tot_row,tot_col,grid,dp);
    int down = memo_recursive(curr_row+1,curr_col,tot_row,tot_col,grid,dp);

    return dp[curr_row][curr_col] = (right%Mod+down%Mod)%Mod;
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<char>> grid(n,vector<char>(m));
    vector<vector<int>> dp(n,vector<int>(m,-1));
    char u;
    int ans = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>u;
            grid[i][j] = u;
        }
    }

    ans = memo_recursive(0,0,n,m,grid,dp);

    cout<<ans<<"\n";

return 0;
}

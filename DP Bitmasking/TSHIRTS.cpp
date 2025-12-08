/*
Problem Link: https://www.codechef.com/problems/TSHIRTS?tab=statement
*/

#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int solve(int shirt_to_wear, int n, int mask, vector<vector<int>> &shirts, vector<vector<int>> &dp){
    
    // base case when all n people are wearing a shirt
    if(__builtin_popcount(mask) == 0){
        return 1;
    }
    
    if(shirt_to_wear > 100){ // no more shirt to explore
        return 0;
    }
    
    // DP check
    if(dp[shirt_to_wear][mask] != -1) return dp[shirt_to_wear][mask];
    
    int answer = 0;
    
    // loop on all people to make him wear given shirt
    for(int i=1;i<=n;i++){
        
        if((mask & (1<<(i-1))) == 0){ // means this person is already wearing some shirt
            continue;
        }
        
        // if person i is not wearing any shirt then we can put on the current shirt_to_wear if he owns it
        if(shirts[i][shirt_to_wear] == 1){
            
            // turn (i-1)th bit off
            int turn_bit = mask ^ (1<<(i-1));
            answer = (answer%MOD + solve(shirt_to_wear+1,n,turn_bit,shirts,dp)%MOD)%MOD;   
        }
    }
    
    // decided not to wear shirt
    answer = (answer%MOD + solve(shirt_to_wear+1,n,mask,shirts,dp)%MOD)%MOD;
    
    return dp[shirt_to_wear][mask] = answer;
}

int main() {
	// your code goes here
    
    int t; 
    cin>>t;
    
    while(t--){
        
        int n;
        cin>>n;
        
        vector<vector<int>> shirts(n+1,vector<int>(101,0));

        for (int i = 1; i <= n; i++) {
            string line;
            getline(cin, line);         // consume leftover newline
            if (line.size() == 0) getline(cin, line);  // read actual line
        
            stringstream ss(line);
            int x;
        
            while (ss >> x) {
                shirts[i][x] = 1;
            }
        }
        
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=100;j++){
        //         cout<<shirts[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        int mask = (1<<n)-1;  // represents n times 11111....111 n times means all n people are not wearing any shirt
        
     //   cout<<__builtin_popcount(mask)<<endl;
        
        vector<vector<int>> dp(102,vector<int>(1<<n,-1));
        
        int ans = solve(1,n,mask,shirts,dp);
        
        cout<<ans<<"\n";
    }
}

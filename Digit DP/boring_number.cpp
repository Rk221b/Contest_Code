/*
Google Kickstart Boring Number Problem H

The "Boring Numbers" problem from Google Kickstart (specifically Round H 2020) involves counting numbers where digits alternate
between odd and even (e.g., 101, 214, 3030), starting with an odd digit (1, 3, 5, 7, 9) for the first position.
Solutions use digit DP (Dynamic Programming) or combinatorial counting: count all shorter boring numbers,
then count longer ones up to the limit, handling the most significant digit (must be odd) and subsequent alternating patterns,
effectively finding numbers with odd/even/odd... or even/odd/even... sequences.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[20][2][2][2];

ll digit_dp(string &num, int n, int even_or_odd, int leading_zeros, int tight){

    /// base case
    if(n == 0)
    {
        /// leading_zeros = 1 means its still on and we can place a 0 and leading_zeros = 0 means we have started putting other digits.
        return leading_zeros == 0 ? 1 : 0;
    }

    if(dp[n][even_or_odd][leading_zeros][tight] != -1) return dp[n][even_or_odd][leading_zeros][tight];

    /// placing digit at even place
    if(even_or_odd == 1) /// means leading_zeros = 0 and we are on even position
    {
        ll answer = 0;
        vector<int> digit = {0,2,4,6,8};
        int upr_bound = tight == 1 ? (num[num.length()-n]-'0') : 9;

        for(int d:digit){
            if(d <= upr_bound)
                answer += digit_dp(num,n-1,0,0,(tight&(upr_bound == d)));
        }

        return dp[n][even_or_odd][leading_zeros][tight] = answer;
    }

    /// odd case
    else if(even_or_odd == 0){

        ll answer = 0;

        if(leading_zeros == 1){ /// we can still place 0 as number has not started
            answer += digit_dp(num,n-1,0,1,0);
        }

        int upr_bound = tight == 1 ? (num[num.length()-n]-'0') : 9;
        vector<int> digit = {1,3,5,7,9};

        for(int d:digit){
            if(d <= upr_bound)
                answer += digit_dp(num,n-1,1,0,(tight&(upr_bound == d)));
        }

        return dp[n][even_or_odd][leading_zeros][tight] = answer;

    }

}

int main(){

    ll L, R;

    cin>>L>>R;

    string l, r;
    L--;

    l = to_string(L);
    r = to_string(R);

    memset(dp,-1,sizeof(dp));
    ll ans1 = digit_dp(l,l.length(),0,1,1);
    memset(dp,-1,sizeof(dp));
    ll ans2 = digit_dp(r,r.length(),0,1,1);

    cout<<(ans2-ans1)<<"\n";

return 0;
}

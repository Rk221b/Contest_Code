/*
 Problem Link : https://leetcode.com/problems/number-of-balanced-integers-in-a-range/description/

 You are given two integers low and high.

An integer is called balanced if it satisfies both of the following conditions:

It contains at least two digits.
The sum of digits at even positions is equal to the sum of digits at odd positions (the leftmost digit has position 1).
Return an integer representing the number of balanced integers in the range [low, high] (both inclusive).



Example 1:

Input: low = 1, high = 100

Output: 9

Explanation:

The 9 balanced numbers between 1 and 100 are 11, 22, 33, 44, 55, 66, 77, 88, and 99.

Example 2:

Input: low = 120, high = 129

Output: 1

Explanation:

Only 121 is balanced because the sum of digits at even and odd positions are both 2.
*/

class Solution
{
    typedef long long ll;
    ll dp[20][400][2][2];
    ll digit_dp(int idx, int dig_len, string &hg, int dig_sum, int has_started, int tight)
    {

        //// base case
        if (idx > dig_len)
        {
            if (has_started == 1 && dig_sum == 0)
                return 1;
            return 0;
        }

        if (dp[idx][dig_sum + 150][has_started][tight] != -1)
            return dp[idx][dig_sum + 150][has_started][tight];

        int upr_bound = tight == 1 ? (hg[idx - 1] - '0') : 9;
        ll ans = 0;
        int sm = 0;

        for (int digit = 0; digit <= upr_bound; digit++)
        {
            sm = (idx % 2 == 0) ? (dig_sum - digit) : (dig_sum + digit);
            // can place 0 if has started is still 0 means not started yet
            if (digit == 0)
            {
                if (has_started == 0)
                {
                    ans += digit_dp(idx + 1, dig_len, hg, sm, 0, (tight & (digit == upr_bound)));
                }
                else
                {
                    ans += digit_dp(idx + 1, dig_len, hg, sm, 1, (tight & (digit == upr_bound)));
                }
            }
            else
            {
                ans += digit_dp(idx + 1, dig_len, hg, sm, 1, (tight & (digit == upr_bound)));
            }
        }

        return dp[idx][dig_sum + 150][has_started][tight] = ans;
    }

public:
    long long countBalanced(long long low, long long high)
    {

        string lw = to_string(low - 1);
        string hg = to_string(high);

        memset(dp, -1, sizeof(dp));
        ll a1 = digit_dp(1, hg.length(), hg, 0, 0, 1);
        memset(dp, -1, sizeof(dp));
        ll a2 = digit_dp(1, lw.length(), lw, 0, 0, 1);

        // cout<<hg<<" answer = "<<a1<<endl;

        return (a1 - a2);
    }
};
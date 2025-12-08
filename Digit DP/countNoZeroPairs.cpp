/*
Problem Link: https://leetcode.com/problems/count-no-zero-pairs-that-sum-to-n/description/
*/

class Solution
{

    long long digit_dp(int idx, int n, vector<int> &nums, unordered_map<string, long long> &dp, int carry, int aliveA, int aliveB)
    {

        // base case
        if (idx == n)
        {
            // if there is carry means number was not formed
            return carry == 0 ? 1 : 0;
        }

        string look_up = to_string(idx) + "@" + to_string(carry) + "@" + to_string(aliveA) + "@" + to_string(aliveB);

        if (dp.find(look_up) != dp.end())
            return dp[look_up];

        long long s = 0, c = 0, ways = 0;

        // aliveA = 1 and aliveB = 1 denotes we are still creating a and b
        // aliveA = 0 means its created now we will use 0 like 0002 in front of it similar for aliveB.

        int astart = aliveA == 1 ? (idx > 0 ? 0 : 1) : 0;
        int bstart = aliveB == 1 ? (idx > 0 ? 0 : 1) : 0;
        int aend = aliveA == 0 ? 0 : 9;
        int bend = aliveB == 0 ? 0 : 9;

        for (int a = astart; a <= aend; a++)
        {
            for (int b = bstart; b <= bend; b++)
            {
                s = (a + b + carry) % 10;
                c = (a + b + carry) > 9 ? 1 : 0;

                int next_alive_A = aliveA == 1 ? (a == 0 ? 0 : 1) : 0; // if alive is 0 then next will also be 0 and if its alive but a is chose 0 then all rest will be 0 only
                int next_alive_B = aliveB == 1 ? (b == 0 ? 0 : 1) : 0; // if alive is 0 then next will also be 0 and if its alive but a is chose 0 then all rest will be 0 only

                if (s == nums[idx])
                {
                    ways = ways + digit_dp(idx + 1, n, nums, dp, c, next_alive_A, next_alive_B);
                }
            }
        }

        return dp[look_up] = ways;
    }

public:
    long long countNoZeroPairs(long long n)
    {

        long long ans = 0;
        vector<int> nums;

        while (n > 0)
        {
            nums.push_back(n % 10);
            n /= 10;
        }

        int sz = nums.size();

        unordered_map<string, long long> dp;

        ans = digit_dp(0, sz, nums, dp, 0, 1, 1);

        return ans;
    }
};
/*
Problem Link: https://leetcode.com/problems/maximum-product-of-two-integers-with-no-common-bits/submissions/1756539987/
*/

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int sz = nums.size();
        int mx = *max_element(nums.begin(),nums.end());

        int bit_size = 32 - __builtin_clz(mx);

        // In general, (1 << B) gives you a binary number with a single 1 at position B and all lower bits = 0.
        // (1 << B) - 1 turns that single 1 into 0, and makes all the lower B bits = 1.
        int max_element_with_bit_size = (1 << bit_size);  

        // Basically DP[i] will denote maximum value for number i or its submasks
        vector<int> dp(max_element_with_bit_size+1, 0); 

        // Base case we will start with all Dp[i] = 0 and max value for i is i if its in nums array
        for(auto num: nums){
            dp[num] = num;
        }

        // Now we will fill the complete Dp array turing off bit [0....bit_size] one by one which will give us submasks
        for(int i=0;i<bit_size;i++){
            for(int num=0;num<=max_element_with_bit_size;num++){
                // if the ith bit is 1 in the number num
                if(((1 << i) & num) != 0){

                    // turn off the ith bit in num now
                    int i_th_bit_turn_off = (1 << i) ^ num;  // a ^ 1 = !a (XOR with 1 flips the bit).

                    dp[num] = max(dp[num], dp[i_th_bit_turn_off]);
                }
            }
        }

        long long ans = 0, tmp = 0;
        int comp;

        for(auto num: nums){
            comp = num^(max_element_with_bit_size-1);
            tmp = (long long)num * (long long)dp[comp];  // num * max value among compliment of num and its all submasks
            ans = max(ans, tmp);
        }
        return ans;
    }
};
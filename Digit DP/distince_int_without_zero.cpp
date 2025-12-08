/*
Problem Link: https://leetcode.com/submissions/detail/1833939175/
*/

class Solution {

    long long int dp[20][2][2];
    
    long long digit_dp(int idx, string &num, bool tight, bool started){

        // base case when number is formed
        if(idx == num.size()){
            return started ? 1 : 0; // count only if a non-zero digit was placed
        }

        //dp lookup
        if(dp[idx][tight][started] != -1) return dp[idx][tight][started];

        // here tight = true denotes that number at index idx can go max upto num[idx]
        // and if its false means its free to go till max number 9
        int limit = tight == true ? (num[idx]-'0') : 9; 

        long long ans = 0;
        // here started = false means we have not started taking digits to form number so it is safe to take 0 as it will         // be leading 0 example 00036
        
        for(int digit=0;digit<=limit;digit++){
            if(digit == 0){ 
                if(started == false){
                    ans += digit_dp(idx+1,num,(tight&&(digit==limit)),false);
                }
            }
            else{ // now we are taking digit
                ans += digit_dp(idx+1,num,(tight&&(digit==limit)),true);
            }
        }
        return dp[idx][tight][started] = ans;
    }
public:
    long long countDistinct(long long n) {

        string num = to_string(n);
        memset(dp, -1, sizeof(dp));
        
        long long ans = 0;
        ans = digit_dp(0,num,true,false);


        return ans;
    }
};
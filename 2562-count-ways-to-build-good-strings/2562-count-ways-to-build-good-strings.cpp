class Solution {
public:

    int sol(int L, int &mod,int &low,int &high,int &zero,int &one, vector<int> &dp){
        if(L > high) return 0;

        if(dp[L] != -1) return dp[L];
        
        int op1 = sol(L + zero, mod, low, high, zero, one, dp) % mod;
        
        int op2 = sol(L + one, mod, low, high, zero, one, dp) % mod;

        int sp = (op1 + op2) % mod;

        if(L >= low && L <= high){
            dp[L] = 1 + sp;
        }else{
            dp[L] = sp;
        }

        return dp[L];
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        int L = 0;
        int mod = 1e9 + 7;
        
        vector<int> dp(high + 1, -1);
        
        int ans = sol(L, mod, low, high, zero, one, dp);

        return ans;
    }
};
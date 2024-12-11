class Solution {
public:
    int sol(vector<int>& coins, int n, int i, int amount, vector<vector<int>> &dp){
        if(amount == 0) return 0; // So, we need no more coins.
        if(amount < 0) return INT_MAX; // Can't be possible.

        // We are here means amount is > 0.
        if(i == n) return INT_MAX; // So, can't be done.

        if(dp[i][amount] != -1) return dp[i][amount]; 

        // Now, we have liberty to choose coints[i] or not.
        // If we include it, we can include it again.
        int val = coins[i];

        int incl = sol(coins, n, i, amount - val, dp);
        // It might happen that sol() is not valid.
        if(incl != INT_MAX) incl = 1 + incl;

        int excl = sol(coins, n, i+1, amount, dp);

        dp[i][amount] = min(incl, excl);
        return dp[i][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int i = 0;
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int ans = sol(coins, n, i, amount, dp);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
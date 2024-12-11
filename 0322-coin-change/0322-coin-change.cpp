class Solution {
public:
    // int sol(vector<int>& coins, int n, int i, int amount, vector<vector<int>> &dp){
    //     if(amount == 0) return 0; // So, we need no more coins.
    //     if(amount < 0) return INT_MAX; // Can't be possible.

    //     // We are here means amount is > 0.
    //     if(i == n) return INT_MAX; // So, can't be done.

    //     if(dp[i][amount] != -1) return dp[i][amount]; 

    //     // Now, we have liberty to choose coints[i] or not.
    //     // If we include it, we can include it again.
    //     int val = coins[i];

    //     int incl = sol(coins, n, i, amount - val, dp);
    //     // It might happen that sol() is not valid.
    //     if(incl != INT_MAX) incl = 1 + incl;

    //     int excl = sol(coins, n, i+1, amount, dp);

    //     dp[i][amount] = min(incl, excl);
    //     return dp[i][amount];
    // }

    int solTab(vector<int>& coins, int n, int amount, vector<vector<int>> &dp){
        // if(amount == 0) return 0; // So, we need no more coins.
        // By default we have taken dp[i][amount] = 0.

        // if(amount < 0) return INT_MAX; // Can't be possible.
        // Will handle this case in runtime.

        // We are here means amount is > 0.
        
        // if(i == n) return INT_MAX; // So, can't be done.
        for(int amnt = 1; amnt <= amount; amnt++) dp[n][amnt] = INT_MAX;
        // So, for all amnt > 0, dp[n][amnt] is INT_MAX.

        // if(dp[i][amount] != -1) return dp[i][amount];

        // Now, we have liberty to choose coints[i] or not.
        // If we include it, we can include it again.
        // int val = coins[i];

        // int incl = sol(coins, n, i, amount - val, dp);
        // It might happen that sol() is not valid.
        // if(incl != INT_MAX) incl = 1 + incl;

        // int excl = sol(coins, n, i+1, amount, dp);

        // dp[i][amount] = min(incl, excl);
        // return dp[i][amount];

        // Now, understand the direction of DP. We want the ans dp[0][amount].
        // So, direction should be from i = n-1 to 0 and amnt = 0 to amount.
        // Draw the rec tree for more clarification.

        for(int i = n-1; i >= 0; i--){
            int val = coins[i];
            for(int amnt = 1; amnt <= amount; amnt++){
                // We will calculate dp[i][amnt].
                int incl;
                if(amnt - val < 0 or dp[i][amnt - val] == INT_MAX) incl = INT_MAX;
                else incl = 1 + dp[i][amnt - val];

                int excl = dp[i+1][amnt];

                dp[i][amnt] = min(incl, excl);
            }
        }
        return dp[0][amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int i = 0;
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        
        int ans = solTab(coins, n, amount, dp);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
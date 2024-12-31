class Solution {
public:

    // int sol(int i,int n,vector<int>& days, vector<int>& costs, vector<int> &dp){
    //     if(i >= n) return 0;

    //     if(dp[i] != -1) return dp[i];


    //     int minCost = INT_MAX;
    //     int nextIdx;
    //     // Now Before calling for each pass, take the nextIdx to correct Index.

    //     // Buy 1-Day Pass. This is trivial, we will go & check next index's day only
    //     // as 1-day pass only covers this day only.
    //     int op1 = costs[0] + sol(i+1, n, days, costs, dp);
        
    //     // Buy 7-Day Pass
    //     for(nextIdx = i; nextIdx < n && days[nextIdx] < days[i] + 7; nextIdx++);
    //     int op2 = costs[1] + sol(nextIdx, n, days, costs, dp);

                
    //     // Buy 30-Day Pass
    //     for(nextIdx = i; nextIdx < n && days[nextIdx] < days[i] + 30; nextIdx++);
    //     int op3 = costs[2] + sol(nextIdx, n, days, costs, dp);

    //     minCost = min(op1, min(op2, op3));

    //     dp[i] = minCost;

    //     return dp[i];

    // }

    int sol(int n, vector<int>& days, vector<int>& costs){
        vector<int> dp(n+1, -1);
        dp[n] = 0;

        // Now we start building from dp[n-1] till dp[0].

        for(int i = n-1; i >= 0; i--){
            int minCost = INT_MAX;
            int nextIdx;

            // Buy 1-Day Pass. // nextIdx is obviously i+1.
            int op1 = costs[0] + dp[i+1];

            // Buy 7-Day Pass.
            for(nextIdx = i; nextIdx < n && days[nextIdx] < days[i] + 7; nextIdx++);
            int op2 = costs[1] + dp[nextIdx]; // nextIdx can't be > n as we have checked in the for().
            // Worst case nextIdx = n and dp[n] = 0. So it is fine.

            // Buy 30-Day Pass.
            for(nextIdx = i; nextIdx < n && days[nextIdx] < days[i] + 30; nextIdx++);
            int op3 = costs[2] + dp[nextIdx]; // nextIdx can't be > n as we have checked in the for().
            // Worst case nextIdx = n and dp[n] = 0. So it is fine.

            minCost = min(op1, min(op2, op3));

            dp[i] = minCost;
        }

        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();

        vector<int> dp(n+1, -1);
        return sol(n, days, costs);
    }
};
class Solution {
public:

    int sol(vector<int>& values, int s, int e, vector<vector<int>> &dp){
        if(e - s < 2) return 0;
        if(e - s == 2) return values[s] * values[s+1] * values[e]; 
        if(dp[s][e] != -1) return dp[s][e];
        int minScore = INT_MAX;

        for(int i = s + 1; i <= e-1; i++){
            int score = sol(values, s, i, dp) + (values[s] * values[i] * values[e]) + sol(values, i, e, dp);
            minScore = min(minScore, score);
        }
        dp[s][e] = minScore;
        return dp[s][e];
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        int s = 0;
        int e = n - 1;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int ans = sol(values, s, e, dp);

        return ans;
    }
};
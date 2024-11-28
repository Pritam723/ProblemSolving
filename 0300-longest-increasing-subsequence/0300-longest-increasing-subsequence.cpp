class Solution {
public:

    int sol(vector<int>& nums, int n, int i, int prevIdx, vector<vector<int>>& dp){
        if(i == n) return 0;

        if(prevIdx != -1 && dp[i][prevIdx] != -1) return dp[i][prevIdx];

        int val = nums[i];

        int incl = 0;
        int excl = 0; // Anyway min length is 0.

        if(prevIdx == -1 or val > nums[prevIdx]){
            // So, in such case I have 2 choice, I can include i,
            // or I can exclude it.
            incl = 1 + sol(nums, n, i + 1, i, dp);
            excl = sol(nums, n, i + 1, prevIdx, dp);

        }else{
            // if val <= nums[prevIdx], so we must exclude it.
            excl = sol(nums, n, i+1, prevIdx, dp);
        }

        if(prevIdx == -1) return max(incl, excl); 

        dp[i][prevIdx] = max(incl, excl);
        return dp[i][prevIdx];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        int prevIdx = -1;

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        int ans = sol(nums, n, i, prevIdx, dp);

        return ans;
    }
};
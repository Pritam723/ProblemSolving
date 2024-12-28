class Solution {
public:

    int Helper(vector<int> &prefixSum, int i, int n, int count, int k, vector<vector<int>> &dp){
        if(count == 3) return 0;
        if(i > n-k) return INT_MIN;

        if(dp[i][count] != -1) return dp[i][count];

        int take = prefixSum[i+k-1] - (i == 0 ? 0 : prefixSum[i-1]) + Helper(prefixSum, i+k, n, count+1, k, dp);
        int not_take = Helper(prefixSum, i+1, n, count, k, dp);

        dp[i][count] = max(take, not_take);
        return dp[i][count];
    }

    void sol(vector<int> &prefixSum, int i, int n, int count, int k,  vector<int> &ans, vector<vector<int>> &dp){
        if(count == 3) return;
        if(i > n-k) return;

        // Take the decision whether to take a SA starting from index i or not.
        int take = prefixSum[i+k-1] - (i == 0 ? 0 : prefixSum[i-1]) + Helper(prefixSum, i+k, n, count+1, k, dp);

        int not_take = Helper(prefixSum, i+1, n, count, k, dp);

        if(take >= not_take){
            ans.push_back(i);
            sol(prefixSum, i + k, n, count + 1, k, ans, dp);
        }else{
            sol(prefixSum, i + 1, n, count, k, ans, dp);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        // int totalSumm = 0; // For this we will take help of Helper Function.
        int count = 0; // Count of Sub Arrays.

        vector<int> prefixSum(n, 0);
        // It will help to get summ from (i, i+k-1) index easily.

        int ps = 0;

        for(int i = 0; i < n; i++){
            ps = ps + nums[i];
            prefixSum[i] = ps;
        }


        vector<int> ans;

        vector<vector<int>> dp(n+1, vector<int>(4, -1));

        sol(prefixSum, i, n, count, k, ans, dp);

        return ans;
    }
};
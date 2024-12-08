class Solution {
public:

    int getUpperBoundIndex(vector<vector<int>>& events, int s, int e, int endTime){
        if(endTime >= events[e][0]) return e+1;

        int ans;

        while(s <= e){
            int m = s + (e-s)/2;
            int startTime = events[m][0];

            if(startTime > endTime){
                ans = m;
                e = m - 1;
            }else{
                s = m + 1;
            }
        }
        return ans;
    }

    static bool comp(vector<int> event1, vector<int> event2){
        return event1[0] < event2[0];
    }

    int sol(vector<vector<int>>& events, int n, int i, int ne, vector<vector<int>> &dp){
        if(i == n or ne >= 2) return 0;

        if(dp[i][ne] != -1) return dp[i][ne];

        // At each index, we have either to choose it or not choose it.
        int excl = sol(events, n, i + 1, ne, dp);

        // If we want to include it check which is the next possible index.
        int endTime = events[i][1];
        
        // int k = i + 1; // But this way we will get TLE again because this is O(N) in worst case.
        // while(k < n && endTime >= events[k][0]) k++;

        int k = getUpperBoundIndex(events, i+1, n-1, endTime); // Search space is index i+1 to n-1.

        int incl = events[i][2] + sol(events, n, k, ne + 1, dp);

        dp[i][ne] = max(incl, excl);
        
        return dp[i][ne];
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), comp);
        
        // vector<int> nums = {1,3,5,6,7,8,9};

        // int idx = upper_bound(nums.begin(), nums.end(), 4) - nums.begin();

        // return idx;
        int i = 0;
        int ne = 0; // No. of events chosen.

        vector<vector<int>> dp(n+1, vector<int>(3, -1));

        int ans = sol(events, n, i, ne, dp);

        return ans;
    }
};
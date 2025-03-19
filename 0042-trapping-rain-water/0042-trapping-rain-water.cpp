class Solution {
public:
    int trap(vector<int>& height) {
        // We need leftMax and rightMax for each point.

        int n = height.size();
        int lm = 0;
        int rm = 0;

        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);

        for(int i = 0; i < n; i++){
            int val = height[i];
            leftMax[i] = lm;

            lm = max(lm, val);
        }

        for(int j = n-1; j >= 0; j--){
            int val = height[j];
            rightMax[j] = rm;

            rm = max(rm, val);
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            ans = ans + max(0, min(leftMax[i], rightMax[i]) - height[i]);
        }

        return ans;
    }
};
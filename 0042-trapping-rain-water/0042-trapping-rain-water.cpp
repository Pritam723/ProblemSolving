class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> maxLeft(n, INT_MIN);
        vector<int> maxRight(n, INT_MIN);

        int maxL = INT_MIN;
        int maxR = INT_MIN;


        // Making maxLeft.
        for(int i = 0; i < n; i++){
            maxLeft[i] = maxL;
            int val = height[i];
            maxL = max(maxL, val);
        }


        // Making maxRight.
        for(int i = n-1; i >= 0; i--){
            maxRight[i] = maxR;
            int val = height[i];
            maxR = max(maxR, val);
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            int maxL = maxLeft[i];
            int maxR = maxRight[i];
            cout << "height is " << height[i] << " " << "left and right are " << maxL << " and " << maxR << endl;

            // if(maxL == INT_MIN or maxR == INT_MIN) continue;
            int side = min(maxL, maxR);
            // cout << "smaller side is " << side << endl;
            if(side == INT_MIN) continue; 
            int net = side - height[i];

            if(net < 0) continue;

            ans = ans + net;
        }

        return ans;
    }
};
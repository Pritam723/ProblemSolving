class Solution {
public:
int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int subsets = pow(2, n);

        // (Say n = 3) Can represent the subsets as bits of 0 to 7.
        int ans = 0;
        for(int subset = 0; subset < subsets; ){
            // cout << "Calculating for ss " << subset << endl;
            int saveSS = subset;
            int xorSum = 0;

            for(int i = n-1; i >= 0; i--){
                int lsb = subset & 1;
                if(lsb == 1) xorSum = xorSum ^ nums[i];
                subset = subset >> 1;
            }
            cout << xorSum << endl;
            ans = ans + xorSum;
            subset = saveSS + 1;

        }
        return ans;
    }
};
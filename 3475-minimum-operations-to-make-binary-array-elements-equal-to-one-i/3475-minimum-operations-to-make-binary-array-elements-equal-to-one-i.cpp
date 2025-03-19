class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isFlipped(n, false);

        int k = 3;

        int i = 0;
        int ans = 0;

        int timesFlipped = 0;

        while(i < n){
            if(i - k >= 0 && isFlipped[i-k] == true) timesFlipped = timesFlipped - 1;

            // Now, based on timesFlipped and nums[i] we decide whether to flip current
            // or not.

            bool isFlipRequired = false;

            if(nums[i] == 1 && (timesFlipped % 2 == 1)) isFlipRequired = true;
            if(nums[i] == 0 && (timesFlipped % 2 == 0)) isFlipRequired = true;

            // Otherwise we do not require to flip.

            if(isFlipRequired && (i + k - 1 > n-1)) return -1;

            if(isFlipRequired){
                isFlipped[i] = true;
                timesFlipped = timesFlipped + 1;
                ans = ans + 1;
            }
            i++;
        }
        return ans;
    }

};
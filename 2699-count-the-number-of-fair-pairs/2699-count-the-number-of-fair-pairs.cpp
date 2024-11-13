class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++){
           int x = lower-nums[i]; // for nums[i], (lower-nums[i]) will be smallest valid number of the pair
           int y = upper-nums[i]; // for nums[i], this will be the largest valid number of the pair
           // now we will find its index in the array
           auto itx = lower_bound(nums.begin()+i+1, nums.end(), x);
           auto ity = upper_bound(nums.begin()+i+1, nums.end(), y);
           ans += ity-itx; 
        }
        return ans;
    }
};
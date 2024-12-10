class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        for(int i = 0; i <= n-3; i++){
            if(nums[i] == nums[i+1] or nums[i] == nums[i+2]) return nums[i];
        }

        return nums[n-1];
    }
};
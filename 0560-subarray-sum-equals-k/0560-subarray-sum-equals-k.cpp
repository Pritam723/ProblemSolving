class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        mp[0] = 1;
        int prefixSum = 0;
        for(int i = 0; i < nums.size(); i++){
            prefixSum = prefixSum + nums[i]; // It gives x say.

            // Now find is there any previous prefixSum having sum = (x - k)?
            // Because if there is, we can remove it to make this subarray (ending at index i)
            // sum = x - (x-k) = k.

            ans = ans + mp[prefixSum - k];

            // Now, push this prefixSum.

            mp[prefixSum] = mp[prefixSum] + 1;
        }
        return ans;
    }
};
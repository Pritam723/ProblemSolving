class Solution {
public:
    void getTwoSum(vector<int> &nums, int s, int e, int tar, vector<vector<int>> &partAns){
        // WKT the array[s:e] is sorted. So, apply 2-pointer approach.

        int previousPoint = INT_MIN; // Initially Can set to anything other than nums[s].

        while(s < e){
            if(nums[s] == previousPoint){
                // cout << "here" << s << endl;
                s++;
                continue;
            }
            if(nums[s] + nums[e] == tar){
                previousPoint = nums[s];
                // cout << nums[s] << " and " << nums[e] <<" makes" << tar << endl;
                partAns.push_back({nums[s], nums[e]});
                s++;
                e--;

            }else if(nums[s] + nums[e] < tar){
                s++;
            }else{
                e--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int target = 0;
        vector<vector<int>> ans;

        int n = nums.size();

        int prevPoint = !nums[0];
        for(int i = 0; i <= n-3; i++){

            if(prevPoint == nums[i]) continue;
            vector<vector<int>> partAns;
            int val = nums[i];
            // cout << "calling for " << val << "  and " << target - val << endl;
            getTwoSum(nums, i + 1, n-1, target-val, partAns);
            // if(partAns.size() == 0) continue;
            for(vector<int> &p: partAns){
                p.push_back(val);
                ans.push_back(p);
            }
            prevPoint = nums[i];
        }
        return ans;
    }
};
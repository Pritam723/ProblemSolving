class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans(n, 1);

        int l2r = 1;
        int r2l = 1;


        for(int i = 0; i < n; i++){
            ans[i] = ans[i] * l2r;
            l2r = l2r * nums[i];
        }

        for(int i = n-1; i >= 0; i--){
            ans[i] = ans[i] * r2l;
            r2l = r2l * nums[i];
        }

        return ans;
    }
};
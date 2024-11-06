class Solution {
public:
    bool checkbits(int a, int b) {
        int bit = 0;
        while (a) {
            bit += (1 & a);
            a = a >> 1;
        }
        while (b) {
            bit -= (1 & b);
            b = b >> 1;
        }
        return bit == 0 ? 1 : 0;
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    if (checkbits(nums[j], nums[j + 1])) {
                        swap(nums[j], nums[j + 1]);
                    }
                }
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
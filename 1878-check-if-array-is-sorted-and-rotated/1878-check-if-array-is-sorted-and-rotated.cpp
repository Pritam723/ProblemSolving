class Solution {
public:
    bool isSorted(vector<int>& nums, int s, int e){
        for(int i = s; i <= e-1; i++){
            if(nums[i+1] < nums[i]) return false;
        }
        return true;
    }
    bool check(vector<int>& nums) {
        int n = nums.size();
        // First find out the first index where,
        // nums[i] < nums[i+1]. If we do not find one, it means array is sorted.
        int pivotIdx = -1;
        for(int i = 0; i <= n-2; i++){
            if(nums[i+1] < nums[i]){
                pivotIdx = i;
                break;
            }
        }

        if(pivotIdx == -1) return true; // It means that nums[n-1] is highest.

        // Otherwise, our array should be sorted in 2 sides of the pivot.
        // As well, the nums[0] should be >= nums[n-1].

        if(nums[0] < nums[n-1]) return false; // Ex. {3,4,5,1,6} is false.

        // Now just check if nums[0:pivot] and nums[pivot+1:n-1] is sorted or not.
        cout << "Here pivot idx is " << pivotIdx << endl;

        if(isSorted(nums, 0, pivotIdx) && isSorted(nums, pivotIdx + 1, n-1)) return true;

        return false;

    }
};
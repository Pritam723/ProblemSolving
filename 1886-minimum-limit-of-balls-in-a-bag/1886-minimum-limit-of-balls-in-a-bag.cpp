class Solution {
public:
    bool isPossible(vector<int> &nums, int n, int penalty, int maxOperations){
        int totalOp = 0;

        for(int i = 0; i < n; i++){
            int num = nums[i];
            // Say num = 19, penalty = 3. Surely operations will be
            // 3,16 -> 3,3,13 -> 3,3,3,10. So we get the point.
            int opRequired;

            // So, careful about cases where num % penalty == 0.
            if(num % penalty == 0) opRequired = num/penalty-1;
            else opRequired = num/penalty;

            totalOp = totalOp + opRequired;

            if(totalOp > maxOperations) return false;
        }

        return true;

    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();

        int s = 1;
        int e = INT_MIN;

        for(int num: nums) e = max(e, num);

        int ans;

        while(s <= e){
            int penalty = s + (e-s)/2;

            // We will check if with maxOperations we can
            // limit our penalty to 'penalty'.

            if(isPossible(nums, n, penalty, maxOperations)){
                cout << "Possible with " << penalty << endl;
                ans = penalty;
                e = penalty - 1;
            }else{
                cout << "Not Possible with " << penalty << endl;

                s = penalty + 1;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // Surely we have 3-choices to form our Sub Sequence.

        // Either all items will be odd.
        // Or all items will be even.

        // Or it should be Odd, Even, Odd, Even,...
        // Otherwise we will not be able to form the valid Sequence.

        int odds = 0, evens = 0;

        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 1) odds++;
            else evens++; 
        }

        // Now, we need to check Alternating Seq. For that first check the nums[0]

        int altSeq = 1; // Because nums[0] will always be in this seq.
        int parity = nums[0] % 2;
        // For even it will be 0, for odd it will be 1.
        // 1 - 0 = 1, 1 - 1 = 0.

        for(int i = 1; i < n; i++){
            int val = nums[i];

            if(val % 2 == 1 - parity){
                altSeq++;
                parity = val % 2;
            }
            // Else we can't include it in our seq. 
        }

        return max(odds, max(evens, altSeq));
    }
};
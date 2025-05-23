class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> xoredNums(n, -1);

        long long ans = 0;
        for(int i = 0; i < n; i ++){
            xoredNums[i] = nums[i] ^ k;
            ans = ans + nums[i];
        }

        // Surely if we xor nums[i] we get xoredNums[i]. (Say x, y)
        // So, gain is y - x. (Can be +ve or -ve).
        // Now, if we revert back from x to y. Gain is x - y (Can be -ve or +ve).
        // So, it is just the negation of previous.
        // Now, push the gain in a max heap.

        priority_queue<int> maxGain;

        for(int i = 0; i < n; i ++){
            int gain = xoredNums[i] - nums[i];
            maxGain.push(gain);
        }

        // Now, in one move we want to take 2 points such that out ans = total gain is maximized.

        while(true){
            int top1 = maxGain.top(); maxGain.pop();
            int top2 = maxGain.top(); maxGain.pop();

            // Surely if we see top1 + top2 <= 0 we will break.

            if(top1 + top2 <= 0) break;

            // Otherwise we take these 2 gains in our answer.

            ans = ans + top1 + top2;

            // And since we have gained these 2, we can push the negation of them in the heap.
            maxGain.push(-top1);
            maxGain.push(-top2);
        }

        return ans;



        return ans;
    }
};
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1, 0);

        if(k == 1){
            for(int i = 0; i < n-k+1; i++) ans[i] = nums[i];
            return ans;
        }

        int i = 0; // Subarray starting from index i.
        // So, we need to move i till n-k index.

        // Starting from each i, we check next k items and see if they are consecutive
        // and increasing.
        while(i <= n-k){
            cout << "Checking for i " << i << endl;
            int j = i + 1; // So, we may start from j = i+1 and check k-1 items.
            while(j < n && nums[j] == nums[j-1] + 1) j++;
            cout << "Got j " << j << endl;
            // So, either j is at n, or we have hit an index that has broken
            // the consecutive streak.

            int count = j-i; // So, starting from i we have got this many numbers
            // that satisfy the rule. Ex. {1,2,3,4,j = 3} so, first 4 satisfies the
            // rule. Since count >= k so we can say in answer array starting from
            // index i till index i + (count - k) index we can put a valid value.

            if(count >= k){
                for(int p = i; p <= i + (count - k); p++) ans[p] = nums[p + k - 1];
                // {1,2,3,4,3}, so for 1 it will be 3 as max.
                // Now, surely from i + (count - k) + 1 index to index j-1. We can put -1.
                // if(j-1 > n - k) break;
                for(int p = i + count - k + 1; p <= n - k && p <= j-1; p++) ans[p] = -1;
            }else{
                // So, imagine a case like {1,2,4}, so it is broken and count = 2 < k.
                // In such case we put all -1 till j-1 index.
                for(int p = i; p <= n - k && p <= j-1; p++) ans[p] = -1;
            }

            // After all these surely, we start checking from index j only.
            i = j;
        }

        return ans;
        
    }
};
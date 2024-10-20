class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        int maxi = nums[0];

        for(int num: nums) maxi = max(num, maxi);

        vector<int> gpd(maxi + 1, -1); // Will store GPD for i = 0 to maxi.
        // For prime numbers it will be -1 only. Consider 1 as prime here.

        for(int i = 2; i <= maxi; i++){
            if(gpd[i] != -1) continue; // No point in checking with non primes.

            // So, otherwise it is prime.
            int j = 2*i;
            int mult = 2;

            while(j <= maxi){
                gpd[j] = max(mult, gpd[j]);
                j = j + i;
                mult++;
            }
        }

        // So, our GPD array is ready. Now scan nums from R to L.
        
        int prevMin = INT_MAX;

        for(int i = n-1; i >= 0; i--){
            int val = nums[i];
            if(val <= prevMin){
                prevMin = val;
                // This is not a violation.
            }else{
                // So, we got a scenario like 25,7.
                if(gpd[val] == -1) return -1;
                val = val/gpd[val];
                ans++;

                if(val > prevMin) return -1; // We can't do it.

                prevMin = val;
            }
        }

        return ans;
    }
};
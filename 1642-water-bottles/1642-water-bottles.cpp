class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int full = numBottles;
        int empty = 0;

        int ans = 0;

        while(full + empty >= numExchange){
            ans = ans + full;
            empty = empty + full;
            full = 0;

            // Now, how many can we exchange? Say we have 11 empty. So,
            // We can get full = 11/3 = 3. And empty remains = 2.

            full = empty/numExchange;
            empty = empty % numExchange;
        }

        // At the end we need to drink the remaining full bottles.
        ans = ans + full;

        return ans;
    }
};
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxnum = 0;

        for (int i = 0; i < 31; i++) {
            int count = 0;
            for (int num : candidates) {
                if (num & (1 << i)) {
                    count++;
                }
            }
            maxnum = max(maxnum, count);
        }
        return maxnum;
    }
};
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // support variables
        long long res = 0;
        int flippables = 0, smallest = INT_MIN;
        // parsing matrix
        for (auto &row: matrix) {
            for (int n: row) {
                // flippable cells (non positive)
                if (n <= 0) {
                    flippables++;
                    smallest = max(smallest, n);
                    res -= n;
                }
                // non flipppable cells (positive)
                else {
                    res += n;
                    smallest = max(smallest, -n);
                }
            }
        }
        return res + (flippables & 1 ? smallest * 2 : 0);
    }
};
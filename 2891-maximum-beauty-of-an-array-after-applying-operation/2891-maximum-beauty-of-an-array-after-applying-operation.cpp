
class Solution {
public:
    int maximumBeauty(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        int startIndex = -1, endIndex = 0, n = v.size(), ans = 0;
        int startInterval = -1e7, endInterval = -1e7;
        for(endIndex = 0; endIndex < n; endIndex += 1) {
            while(v[endIndex] - k > endInterval) {
                startIndex += 1;
                startInterval = v[startIndex] - k, endInterval = v[startIndex] + k;
            }
            ans = max(ans, endIndex - startIndex + 1);
        }
        return ans;
    }
};
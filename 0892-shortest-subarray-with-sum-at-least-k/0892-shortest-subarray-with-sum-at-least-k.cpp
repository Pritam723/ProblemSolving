class Solution {
public:
    int shortestSubarray(vector<int>& arr, int k) {
        deque<pair<int, int>> dq;
        int n = arr.size();
        int sum = 0;
        int ans = INT_MAX;
        int l = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            dq.push_back(make_pair(arr[i], i));
            while (!dq.empty() && dq.back().first < 0) { // Merge
                int lastValue = dq.back().first;
                dq.pop_back();
                if (!dq.empty())
                    dq.back() = make_pair(dq.back().first + lastValue, i) ;
            }
            if (sum <= 0) {
                dq.clear();
                sum = 0;
                l = i+1;
            }
            while (!dq.empty() && sum-dq.front().first >= k) {
                int prevValue = dq.front().first;
                int index = dq.front().second;
                dq.pop_front();
                sum -= prevValue;
                l = index + 1;
            }
            if (sum >= k) {
                ans = min(ans, i - l + 1);
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
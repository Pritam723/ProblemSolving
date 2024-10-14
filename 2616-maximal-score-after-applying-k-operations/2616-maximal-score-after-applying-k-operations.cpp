class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxPQ;
        for(int num: nums) maxPQ.push(num);
        long long ans = 0;
        while(maxPQ.top() != 0 && k > 0){
            int val = maxPQ.top(); maxPQ.pop();
            // cout << val << endl;
            ans = ans + (long long)val;
            if(val % 3 == 0) val = val/3;
            else val = val/3 + 1;
            maxPQ.push(val);
            k--;
        }
        return ans;
    }
};
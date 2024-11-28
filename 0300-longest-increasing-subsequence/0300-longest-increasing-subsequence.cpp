class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> seq;
        // [0,1,0,3,2,3]
        // 0,1,2,3

        for(int i = 0; i < n; i++){
            int val = nums[i];

            cout << val << endl;

            if(seq.size() == 0 or val > seq.back()) seq.push_back(val);
            else{
                int idx = lower_bound(seq.begin(), seq.end(), val) - seq.begin();
                cout << "got idx " << idx << endl;
                seq[idx] = val;
            }
        }
        return seq.size();
    }
};
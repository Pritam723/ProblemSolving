class Solution {
public:
    void sol(vector<int>& candidates, int n, int i, int target, vector<vector<int>> &ans, vector<int> &pa){
        if(target == 0){
            ans.push_back(pa);
            return;
        }

        if(i == n) return; // So, target != 0.
        if(target < 0) return; // No point in checking.

        int val = candidates[i];

        // Include it.
        pa.push_back(val);
        sol(candidates,n,i + 1,target - val,ans,pa);
        pa.pop_back();

        // While excluding, exclude all val.
        while(i < n && candidates[i] == val) i++;
        // So now i is at n or candidates[i] != val
        sol(candidates,n,i,target,ans,pa);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        int i = 0;

        vector<vector<int>> ans = {};
        vector<int> pa = {};

        sort(candidates.begin(), candidates.end());

        sol(candidates,n,i,target,ans,pa);

        return ans;
    }
};
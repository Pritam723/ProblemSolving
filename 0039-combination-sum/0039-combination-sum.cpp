class Solution {
public:

    void sol(vector<int>& candidates, int n, int i,int target, vector<int> &pa, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(pa);
            return;
        }

        if(i == n) return; // Surely target is != 0 here.

        if(target < 0) return; // If ever target becomes < 0, there is no point to check further.

        int val = candidates[i];

        // Either we can include val or exclude it.
        pa.push_back(val);
        sol(candidates, n, i, target - val, pa, ans); // No need to do i+1 as same value can be re-included.
        pa.pop_back();

        sol(candidates, n, i + 1, target, pa, ans);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int i = 0;
        
        vector<vector<int>> ans = {};
        vector<int> pa = {};

        sol(candidates, n, i, target, pa, ans);

        return ans;
    }
};
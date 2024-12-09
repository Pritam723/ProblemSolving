class Solution {
public:
    int getParity(int a){
        return a % 2;
    }

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> specialArrayTillIdx(n, -1);
        int m = queries.size();

        vector<bool> ans(m, false);

        int i = 0;
        while(i < n){
            int j = i;
            while((j < n-1) && (getParity(nums[j]) != getParity(nums[j+1]))) j = j+1;
            // We are here ,means j = n-1 or we got same parity of j+1 and j.

            // So, starting from index i to j fill specialArrayTillIdx[idx] = j.
            while(i <= j) specialArrayTillIdx[i++] = j;

            // Now start from index i = j+1.
            // i = i + 1; // So not need to do this.
        }
        
        int k = 0;
        while(k < m){
            vector<int> query = queries[k];
            int s = query[0];
            int e = query[1];

            if(e <= specialArrayTillIdx[s]) ans[k] = true;
            k = k + 1;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n = A.size();

        vector<int> ans(n, 0);

        int count = 0;

        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;

        for(int i = 0; i < n; i++){
            int val1 = A[i];
            int val2 = B[i];

            if(val1 == val2){
                count = count + 1;
            }else{
                // So, values are different.
                count = count + mp1[val2];
                count = count + mp2[val1];
            }

            mp1[val1] = 1;
            mp2[val2] = 1;

            ans[i] = count;
        }
        return ans;

    }
};
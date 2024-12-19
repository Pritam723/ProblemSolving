class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int maxTillNow = INT_MIN;

        int l = 0, r = 0;

        int count = 0;

        while(l < n){
            int val = arr[l];
            maxTillNow = max(val, maxTillNow);

            // So, if we got max = 2, we must at least go till index 2 for sure.
            if(maxTillNow == l){
                count++;
                maxTillNow = INT_MIN;
                l = l + 1;
            }else{
                l = l + 1;
            }
        }

        return count;
    }
};
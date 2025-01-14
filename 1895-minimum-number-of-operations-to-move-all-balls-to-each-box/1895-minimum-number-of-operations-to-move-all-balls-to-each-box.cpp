class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);

        int places = 0;
        int movesRL = 0;
        int movesLR = 0;
        
        for(int i = 0; i < n; i++){
            char ch = boxes[i];

            if(ch == '1'){
                places++;
                movesRL = movesRL + (i+1);
                movesLR = movesLR + (n-i);
            }
        }

        int p = places;
        // First Go L to R.
        for(int i = 0; i < n; i++){
            movesRL = movesRL - p;
            ans[i] = ans[i] + movesRL;
            if(boxes[i] == '1') p = p - 1;
        }

        p = places;
        // First Go R to L.
        for(int i = n-1; i >= 0; i--){
            movesLR = movesLR - p;
            ans[i] = ans[i] + movesLR;
            if(boxes[i] == '1') p = p - 1;
        }



        return ans;

    }
};
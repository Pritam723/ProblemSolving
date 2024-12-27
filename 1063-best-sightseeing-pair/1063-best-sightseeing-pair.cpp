class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // See, we have i < j. So, at any point think about
        // fixing/choosing the j. Intially we start from j = 1,
        // so, this way we only have one choice i.e., i = 0.

        // For j = 2, we have 2 choices i.e., i = 0 or i = 1,
        // but here we will apply similar idea of Kadane's or Best
        // Time to Buy or Sell stock-1 to minimize the calculation.
        int n = values.size();
        int i = 0, j = 1;
        // int diff = i - j;

        int maxEndingHere = values[i] + i + values[j] - j; // What is the max while choosing j as one of the value.
        
        // So, i's contribution is values[i] + i
        // j's contribution is values[j] - j

        int maxScore = maxEndingHere; // Max score till now.


        // So, now we go from j = 2 to n-1.
        for(j = 2; j < n; j++){
            // Since we have moved j = j + 1, so, we now have liberty
            // to choose an extra item for i. Ex. If j = 2 now, so, we
            // can choose i = 1 too. So, we need to check whether that
            // would benifit us over previous i.
            
            // So, first update max ending here first. (It is local maxima).
            // Then we update maxScore till now. (Global Maxima).

            // For local maxima first compare with the previous i.

            int score1 = values[j] + values[i] + (i-j);
            int score2 = values[j] + values[j-1] - 1;

            // Run few test cases, we will see local maxima is either one of these 2 scores.
            // Say we are at j = 6, and previously chosen i for j = 5's local maxima was 2.
            // Then for j = 6, either i = 2 or i = 5 will give local maxima. Why so? To prove that,
            // Let's use a counter example.
            // Say for j = 5 we get local maxima = values[2] + 2 + values[5] - 5.
            // For j = 6 can we get something better over i = 2 with i = 3? For that
            // i's contribution will be values[3] + 3. We are saying values[3] + 3 > values[2] + 2
            // for j = 6. If that is the case for j = 5 also it would have been true.
            // So, we need to check these 2 cases only.

            if(score2 > score1){
                maxEndingHere = score2;
                i = j-1; // We need to update i obviously.
            }else{
                maxEndingHere = score1;
                // No need to update i.
            }

            // Finally update global maxima.
            maxScore = max(maxScore, maxEndingHere);
        }
        return maxScore;
    }
};
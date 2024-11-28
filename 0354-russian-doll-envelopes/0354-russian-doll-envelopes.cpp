class Solution {
public:

    static bool comp(vector<int> e1, vector<int> e2){
        if(e1[0] < e2[0]) return true;
        else if(e1[0] == e2[0]){
            // Then sort based on height DESC.
            return e1[1] > e2[1];
        }else{
            return false;
        }
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end(), comp);
        // for(vector<int> envelope: envelopes){
        //     cout << envelope[0] << " " << envelope[1] << endl;
        // }

        // Now, we have sorted on Width ASC, and on Height DESC.
        // Apply LIS on Height.

        vector<int> seq;

        for(int i = 0; i < n; i++){
            int height = envelopes[i][1];

            if(seq.size() == 0 or height > seq.back()) seq.push_back(height);
            else{
                int idx = lower_bound(seq.begin(), seq.end(), height) - seq.begin();
                seq[idx] = height;
            }
        }

        return seq.size();
    
    }
};
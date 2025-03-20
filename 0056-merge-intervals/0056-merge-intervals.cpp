class Solution {
public:
    // bool static comp(vector<int> e1, vector<int> e2){
    //     if(e1[0] <= e2[0]) return true;
    //     else{
    //         if(e1[1] < e2[1]) return true;
    //         else return false;
    //     }
    // }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        // return intervals;
        vector<vector<int>> newIntervals;

        int n = intervals.size();

        vector<int> prevInterval = {-1,-1};

        for(int i = 0; i < n; i++){
            vector<int> currInterval = intervals[i];
            if(prevInterval[0] == -1){
                prevInterval = currInterval;
                continue;
            }

            // Otherwise, we must compare curr with prev.
            if(prevInterval[1] >= currInterval[0]){
                // So, we need to merge it. But here comes 2 scenarios.
                int start, end;

                cout << currInterval[0] << "," << currInterval[1] << endl;
                cout << prevInterval[0] << "," << prevInterval[1] << endl;

                if(currInterval[1] <= prevInterval[1]){
                    // Completely inside prevInterval.
                    cout << "this case" << endl;
                    start = prevInterval[0];
                    end = prevInterval[1];
                }else{
                    cout << "that case" << endl;
                    start = prevInterval[0];
                    end = currInterval[1]; 
                }
                cout << start << "," << end << endl;
                prevInterval[0] = start;
                prevInterval[1] = end;
            }else{
                // So, it is not overlapping.
                newIntervals.push_back(prevInterval);
                prevInterval = currInterval;
            }
        }

        newIntervals.push_back(prevInterval);


        return newIntervals;
    }
};
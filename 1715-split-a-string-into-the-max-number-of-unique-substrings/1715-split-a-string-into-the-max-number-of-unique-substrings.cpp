class Solution {
public:

    int sol(string &s, int &n, int start, unordered_map<string, bool> &mp){
        if(start == n) return 0; // It means that till index n-1 we got
        // a unique newSS. We can safely return 0 now.

        if(start == n-1){
            // What we return will depend on mp[s.substr(n-1)]
            // is unique or not.
            string newSS = s.substr(n-1);
            if(mp[newSS] == false) return 1;
            else return INT_MIN; // Returning INT_MIN
            // means it is not possible to get the split.
        }

        // Now, our current SS is starting from index start.
        // So, our choice is to end this SS at end = start or start+1
        // or start+2,... till end = n-1.

        int maxSplit = INT_MIN;

        for(int end = start; end < n; end++){
            string newSS = s.substr(start, end-start+1);
            if(mp[newSS] == true) continue;
            // So, we can't end the SS here.
    
            // If it is not found in mp, we have 2 options
            // Either take this SS or not take it. Not taking
            // the SS will be covered by the loop itself. So,
            // analyse the case where we are taking the SS as new.

            mp[newSS] = true;
            int op1 = sol(s, n, end+1, mp); // Next SS is starting from end+1.
            
            // Now op1 can be INT_MIN, i.e., It is impossible to split further
            // in case we consider newSS. So, do not consider it. But before
            // continuing be very careful, we must mark mp[newSS] = false for next round.

            if(op1 == INT_MIN){ 
                mp[newSS] = false;
                continue; // So, we do not consier this split.

                // If all splits are impossible maxSplit = INT_MIN will be returned.
            }
            maxSplit = max(1 + op1, maxSplit);

            // Now, for the next iteration we backtrack.
            mp[newSS] = false;
        }

        return maxSplit;
    }

    int maxUniqueSplit(string s) {
        int n = s.length();

        unordered_map<string, bool> mp;

        // int count = 0; // Count number of SS.

        int start = 0; // Signifies start of the current SS.
        
        int ans = sol(s, n, start, mp); // No need to worry about INT_MIN here
        // as atleast 1 will be returned here.

        return ans;
    }
};
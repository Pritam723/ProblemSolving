class Solution {
public:
    int maximumLength(string s) {
        // If we ever see "aaaa", it means we have
        // twice "aaa", thrice "aa", 4 times "a".
        // So, save the count in hashmap like that.
        unordered_map<string, int> mp;
        int i = 0;
        int n = s.length();

        while(i < n){
            // See how far we can get same character.
            char ch = s[i];
            int j = i;
            while(j < n && s[j] == ch) j++;
            // So, either j == n or s[j] != ch.
            // So, from index i to j-1 we have same char.
            // Say we get "aaaa" we add mp[a] = 4, mp[aa] = 3,
            // mp[aaa] = 2, mp[aaaa] = 1.
            int ssLength = j - i;
            for(int l = 1; l <= ssLength; l++){
                string ss = s.substr(i, l);
                mp[ss] = mp[ss] + (ssLength - l + 1);
            }
            // After this we need to start processing from j.
            i = j;
        }
        // Now check the map and take the maxLength ss.
        int maxLen = -1;
        for(pair<string, int> p: mp){
            string ss = p.first;
            int ssLength = ss.length();
            int count = p.second;

            if(count < 3) continue; // No need to consider.

            maxLen = max(ssLength, maxLen);
        }
        return maxLen;
    }
};
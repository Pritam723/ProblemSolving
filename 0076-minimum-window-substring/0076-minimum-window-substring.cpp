class Solution {
public:
    string minWindow(string s, string t) {
        
        string ans = "";
        int minLength = INT_MAX;

        int m = s.length();
        int n = t.length();

        unordered_map<char, int> needMap;
        unordered_map<char, int> haveMap;

        int needCount = 0;
        int haveCount = 0;

        for(char ch: t){
            needMap[ch]++;
            needCount++;
            haveMap[ch] = 0;
        }

        // Now, we apply Sliding Window Technique on s.
        int l = 0, r = 0;
        while(r < m){
            char ch  = s[r];
            if(needMap.count(ch) == 0){
                r = r + 1; 
                // Basically adding it or not adding it does not matter.
                // Also no need to take this string as consideration as
                // if it is eligible then string previous to it is also
                // eligible.
                continue;
            }
            
            // We are here means this character is a important character.
            // First add it in haveMap.
            haveMap[ch]++;
            // Now, check if adding it actually helped in contribution.
            // For example, we need 2 no. of 'A's. And we have 3 no. of 'A's already.
            // Then getting an 'A' now is not actually a contribution actually.
            if(haveMap[ch] <= needMap[ch]) haveCount++;

            // Now, check if haveCount has become needCount or not.
            if(haveCount < needCount){
                r = r + 1;
                continue;
            }

            // It means haveCount == needCount now. So, this is an eligible substring.
            // This SS has length = r-l+1. But before saving this SS, can we make it little
            // bit smaller? Ex. s = "DEAAFBCGH", t = "ABC". Now, say we are at r = 6, so we see
            // haveCount == needCount with the SS "DEAAFBC". So, rather than saving entire SS,
            // try to cut it short from left. See, even after removing "DEA" part, we are left with
            // "AFBC" which satisfies our requirement. Which is also a better choice.

            while(true){
                char chDel = s[l];
                if(needMap.count(chDel) == 0){
                    // No need to think just delete it.
                    l = l + 1;
                    continue;
                }

                // So, it is an important character.
                if(haveMap[chDel] == needMap[chDel]) break; // So, we can not delete it.
                // So, we can break here.

                // Otherwise we can delete it as haveMap[chDel] must be > needMap[chDel] for this chDel.
                haveMap[chDel]--;
                l = l + 1;
            }

            // Now, we are here means we are at a potential minimum SS.
            cout << "Found from " << l << " to " << r << endl;
            if(r-l+1 < minLength){
                minLength = r-l+1;
                ans = s.substr(l, minLength);
            }

            // But before moving to r + 1, we also need to do l + 1 and delete
            // the character at index l to make haveCount < needCount again.
            // Otherwise again in next character we will face the haveCount == needCount
            // case. Or infact haveCount >= needCount case.
            haveMap[s[l]]--;
            haveCount--;
            l = l + 1;
            r = r + 1;
        }

        return ans;

    }
};
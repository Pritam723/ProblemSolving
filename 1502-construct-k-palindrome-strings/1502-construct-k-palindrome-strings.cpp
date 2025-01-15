class Solution {
public:
    bool canConstruct(string s, int k) {
        // Refer. https://www.youtube.com/watch?v=nR7MldpnRL4
        // Also see hints.

        int n = s.length();

        if(k > n) return false;

        vector<int> charFreq(26, 0);

        for(char ch: s){
            int chIdx = int(ch) - int('a');
            charFreq[chIdx]++;
        }

        int odd = 0;

        for(int f: charFreq){
            if(f%2 == 1) odd++;
        }

        if(odd > k) return false;

        return true;
    }
};
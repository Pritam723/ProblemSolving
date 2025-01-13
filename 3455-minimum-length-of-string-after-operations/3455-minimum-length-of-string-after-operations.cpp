class Solution {
public:
    int minimumLength(string s) {
        vector<int> charMap(26, 0);

        int n = s.length();

        // Take examples, we can apply Greedy here.
        // Whenever we see 3 same characters, delete 2.
        // No need to think about indices.

        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            int idx = ch - 'a';

            charMap[idx]++;

            if(charMap[idx] == 3){
                n = n - 2;
                charMap[idx] = charMap[idx] - 2;    
            }
            
        }

        return n;
    }
};
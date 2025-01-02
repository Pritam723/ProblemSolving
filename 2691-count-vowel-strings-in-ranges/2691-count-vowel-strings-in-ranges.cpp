class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u') return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int m = words.size();
        int n = queries.size();
        vector<int> countWords(m, 0);

        int count = 0; // Till index -1 we have 0 words which start and end with a vowel.

        for(int i = 0; i < m; i++){
            string word = words[i];
            int L = word.length();
            if(isVowel(word[0]) && isVowel(word[L-1])) count++;
            
            countWords[i] = count;
        }

        vector<int> ans;
        for(vector<int> query: queries){
            int s = query[0] - 1;
            int e = query[1];

            int incl = countWords[e];
            int excl = (s < 0 ? 0 : countWords[s]); 

            int pa = incl - excl;
            ans.push_back(pa);
        }

        return ans;
    }
};
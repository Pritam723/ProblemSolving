class Solution {
public:

    void separateWords(string &s, vector<string> &words, unordered_map<string, int> &countMap){
        int n = s.length();

        int i = 0;

        while(i < n){
            int j = i;
            while(j < n && s[j] != ' ') j++;

            // So, j is n or s[j] is space.
            string subS = s.substr(i, j-i); // Don't do +1 as we dont want to take the space.
            words.push_back(subS);

            i = j+1;
        }

        for(string word: words) countMap[word]++;
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;

        vector<string> words1;
        vector<string> words2;

        unordered_map<string, int> countMap1;
        unordered_map<string, int> countMap2;

        separateWords(s1, words1, countMap1);
        separateWords(s2, words2, countMap2);

        for(string word: words1){
            // cout << word << " " << countMap1[word] << " and " << countMap2[word] << endl;
            if(countMap1[word] == 1 && countMap2[word] == 0) ans.push_back(word);
        }


        for(string word: words2){
            // cout << word << " " << countMap1[word] << " and " << countMap2[word] << endl;

            if(countMap2[word] == 1 && countMap1[word] == 0) ans.push_back(word);
        }

        return ans;
    }
};
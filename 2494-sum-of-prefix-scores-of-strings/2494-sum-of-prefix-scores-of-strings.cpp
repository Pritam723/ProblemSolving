class TrieNode{
public:
    char ch;
    bool isTerminal;
    int visitCount = 0;
    TrieNode* children[26];

    TrieNode(char ch){
        this->ch = ch;
        this->isTerminal = false;
        this->visitCount = 0;
        // Because we have a to z only.
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};


class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }

    void insert(string &s){
        int n = s.length();
        TrieNode* t = root;
        int i = 0;
        while(i < n){
            int ch = s[i] - 'a';
            if((t->children)[ch] != NULL){
                // So, the character is already there.
                t = (t->children)[ch];
                t->visitCount = t->visitCount + 1;
            }else{
                // So, we need to ad the character.
                (t->children)[ch] = new TrieNode(ch);
                t = (t->children)[ch];
                t->visitCount = t->visitCount + 1;
            }
            // Now increment i.
            i = i + 1;
        }
        // After loop mark the last node as terminal.
        t->isTerminal = true;
    }

    int getPrefixScore(string &s){
        int n = s.length();
        TrieNode* t = root;
        int i = 0;
        int score = 0;
        for(int i = 0; i < n; i++){
            int ch = s[i] - 'a';
            if((t->children)[ch] == NULL) break;
            t = (t->children)[ch];
            score = score + t->visitCount;
        }

        return score;
    }
};





class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        Trie trie = Trie();
        for(string word: words) trie.insert(word);

        // Now again traverse the words to get the answer.
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++){
            ans[i] = trie.getPrefixScore(words[i]);
        }

        return ans;
    }
};
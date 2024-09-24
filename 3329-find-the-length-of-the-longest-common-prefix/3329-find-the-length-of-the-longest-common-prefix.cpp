class TrieNode{
public:
    char ch;
    bool isTerminal;
    vector<TrieNode*> children;

    TrieNode(char ch){
        this->ch = ch;
        this->isTerminal = false;
        children.resize(10, NULL); // Because we have 0 to 9 only.
    }
};


class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }

    void insert(string s){
        int n = s.length();
        TrieNode* t = root;
        int i = 0;
        while(i < n){
            int ch = s[i] - '0';
            if((t->children)[ch] != NULL){
                // So, the character is already there.
                t = (t->children)[ch];
            }else{
                // So, we need to ad the character.
                (t->children)[ch] = new TrieNode(ch);
                t = (t->children)[ch];
            }
            // Now increment i.
            i = i + 1;
        }
        // After loop mark the last node as terminal.
        t->isTerminal = true;
    }

    int checkCommonLength(string s){
        int n = s.length();
        // See while checking either we hit length n first.
        // Or we hit end of the Trie chain. Or we may hit a mismatch.
        // That is basically chain break. So, we see how far we can go.
        TrieNode* t = root;
        int i = 0;
        int length = 0;
        while(i < n){
            int ch = s[i] - '0';
            if((t->children)[ch] == NULL) break; // Means it is a mismatch.
            // Not breaking means we got the character.
            length++;
            t = (t->children)[ch];
            // Now move to next character.
            i = i + 1;
        }

        return length;

    }
};


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // Brute force may take O(N^2) i.e., T.L.E. Instead make a
        // try out of one array and then take items from arr2 one by one
        // and check.
        Trie trie = Trie();
        for(int num: arr1) trie.insert(to_string(num));

        int maxLength = INT_MIN;
        // Now, one by one we need to check arr2 items.
        for(int num: arr2){
            string s = to_string(num);
            int length = trie.checkCommonLength(s);
            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
};
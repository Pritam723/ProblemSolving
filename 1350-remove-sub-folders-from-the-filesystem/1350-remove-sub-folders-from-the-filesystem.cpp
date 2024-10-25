class TrieNode{
public:
    char ch;
    TrieNode* children[27];
    // Using 1 extra char for '/'.
    bool isTerminal;

    TrieNode(char ch){
        this->ch = ch;

        for(int i = 0; i < 27; i++){
            children[i] = NULL;
        }

        this->isTerminal = false;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string word){
        int i = 0;
        int n = word.length();

        // If word is of 0 length do this.
        if(n == 0){
            root->isTerminal = true;
            return;
        }

        TrieNode* temp = root;

        while(i < n){

            // if(temp->isTerminal == true) return;
            // If we ever see this for a word, we are
            // sure that it is a subfolder, so no need
            // to check it. But it is wrong. Take the
            // Ex. "/a/b/c","/a/b/ca".

            char ch = word[i];
            int chVal = ch - 'a';

            if(ch == '/') chVal = 26;

            // Now, if it is a '/' we need to check if temp is terminal or not.
            // Ex. "/a/b/c", "a/b/c/d", So, at '/' after c, we will see that
            // c is terminal, so no need to add. But see it is fail proof. See
            // the example "/a/b/c", "a/b/cd" it will still add 'd'.
            if(chVal == 26 && temp->isTerminal == true) return;

            TrieNode *child = temp->children[chVal];

            // Now, child can be NULL.
            if(child == NULL){
                TrieNode *newNode = new TrieNode(ch);
                temp->children[chVal] = newNode;
            }

            // Now, we move temp and i to next charcter.
            temp = temp->children[chVal];
            i++;
        }

        // We are here means we have added the word. So, just set the isTerminal of temp.
        temp->isTerminal = true;
        return;
    }
};

void dfs(TrieNode* tn, string &output, vector<string> &ans){
    if(tn->isTerminal == true){
        ans.push_back(output);
        // Do not return here, imagine the case "/a/b/c","/a/b/ca".
        // return;
    }

    // Standing at a tn, we need to visit all its children.
    for(int i = 0; i < 27; i++){
        TrieNode* child = tn->children[i];
        if(child == NULL) continue;

        char ch = child->ch;
        output.push_back(ch);
        dfs(child, output, ans); 
        output.pop_back();
    }
}



class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        sort(folder.begin(), folder.end());
        
        vector<string> ans;

        Trie t = Trie();

        for(string f: folder) t.insert(f);

        // Now, just traverse the Trie and take folders
        // till first terminal hits. Also, search is written
        // in such a way that subfolders are eliminated anyway.

        string output = "";
        dfs(t.root, output, ans); 

        return ans;
    }
};
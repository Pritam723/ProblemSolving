class Solution {
public:

    bool isConnected(string &word1, string &word2){
        // All words are of same length.
        int L = word1.length();

        int differs = 0;

        for(int i = 0; i < L; i++){
            if(word1[i] != word2[i]) differs++;

            if(differs > 1) return false;
        }

        // differs will never be 0 as all are different.
        return true;
    }



    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Basically we can make a graph out of these words.
        unordered_map<string, bool> mp;
        unordered_map<string, vector<string>> adjList;
        unordered_map<string, bool> visited;

        queue<string> bfsQ;

        for(string word: wordList){
            mp[word] = true;
            visited[word] = false;
            if(isConnected(word, beginWord)){
                bfsQ.push(word);
                visited[word] = true;
            }
        }

        if(mp[endWord] == false) return 0;

        int n = wordList.size();

        

        for(int i = 0; i < n; i++){
            string word1 = wordList[i];
            for(int j = i+1; j < n; j++){
                string word2 = wordList[j];
                if(isConnected(word1, word2)){
                    adjList[word1].push_back(word2);
                    adjList[word2].push_back(word1);
                }
            }
        }

        int step = 1;

        while(!bfsQ.empty()){
            int sz = bfsQ.size();

            if(visited[endWord] == true)
                break;

            step = step + 1;

            for(int i = 0; i < sz; i++){
                string fn = bfsQ.front();
                bfsQ.pop();

                vector<string> neighbours = adjList[fn];

                for(string neighbour: neighbours){
                    if(visited[neighbour] == true) continue;

                    bfsQ.push(neighbour);

                    visited[neighbour] = true;

                }
            }
        }

        if(visited[endWord] == true) return step + 1;

        return 0;



    }
};
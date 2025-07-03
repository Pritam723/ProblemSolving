class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";

        while(word.length() < k){
            string newPart;
            for(char ch: word){
                int offset = (ch - 'a' + 1) % 26;
                char newCh = 'a' + offset;
                newPart.push_back(newCh);
            }
            word = word + newPart;
        }
        return word[k-1];
    }
};
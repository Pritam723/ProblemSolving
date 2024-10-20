class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;

        string fixedString = "";
        int len = 0;

        // Each time a char will be added to fixedString and len will be++.

        for(char ch: target){
            int dist = ch - 'a';
            // cout << "char is " << ch << " dist is " << dist << endl;
            fixedString.push_back('a');
            len++;

            for(int i = 0; i <= dist; i++){
                char newCh = 'a' + i;
                fixedString[len-1] = newCh;

                // cout << fixedString << endl;
                ans.push_back(fixedString);
            }
        }
        return ans;
    }
};
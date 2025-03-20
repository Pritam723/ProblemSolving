class Solution {
public:
    unordered_map<char,string> numberMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void sol(string &digits, int n, int i, vector<string> &ans){
        if(i == n) return;
        
        char ch = digits[i];
        string s = numberMap[ch];

        if(i == 0){
            for(char ch : s){
                string t;
                t.push_back(ch);
                ans.push_back(t);
            }
        }else{
            vector<string> pa;
            for(string t: ans){
                for(char ch: s){
                    string t2 = t;
                    t2.push_back(ch);
                    pa.push_back(t2);
                }
            }
            ans = pa;
        }

        // Now call next.
        sol(digits, n, i + 1, ans);
        return;
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        int i = 0;

        vector<string> ans;
        sol(digits, n, i, ans);

        return ans;
    }
};
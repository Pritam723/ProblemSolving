class Solution {
public:

    string getReverse(string &word){
        int n = word.length();
        int start = 0, end = n-1;
        string rev = "";

        while(end >= 0){
            rev.push_back(word[end]);
            end--;
        }

        return rev;
    }

    bool isPalindrome(string &word){
        int n = word.length();
        int start = 0, end = n-1;

        while(start < end){
            if(word[start] != word[end]) return false;
            start++;
            end--;
        }

        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> mp;
        int n = words.size();

        for(int i = 0; i < n; i++){
            string word = words[i];
            string rev = getReverse(word);
            mp[rev] = i;
        }

        // Case-1: Is there any empty string? Careful, do not take "" twice.
        if(mp.count("") > 0){
            int emptyIdx = mp[""];
            for(int i = 0; i < n; i++){
                if(i == emptyIdx) continue;
                string word = words[i];
                if(isPalindrome(word)){
                    ans.push_back({i, emptyIdx});
                    ans.push_back({emptyIdx, i});
                }
            }
        }

        // Case-2: Reflection Case. abcd, dcba. Careful, do not take palindromes twice.
        for(int i = 0; i < n; i++){
            string word = words[i];
            // string rev = getReverse(word);

            if(mp.count(word) > 0 && mp[word] != i){
                ans.push_back({i, mp[word]});
            }
        }

        // Case-3: The tricky case, where we need to split the string and check continuously.
        // Ex1. "lls", "sssll" -> can form "lls" + "sssll". Why? Beacause sssll can be split
        // like "ss" | "sll", and left part "ss" is palindrome and for the right part we have mp[rev("lls")]
        // existing. So, in this case we will take {mp[rev("lls")], i}.
        // Ex2. "abcdd", "cba". We split "abc" | "dd". So, right part is palindrome. And for the left part
        // "abc" we have mp[rev("abc")] existing. So, we take {i, mp[rev("abc")]}.
        // Do not cut such that one part is empty, as that case is already handled in Case-1.

        for(int i = 0; i < n; i++){
            string word = words[i];
            int len = word.length();
            // int cutIdx = 1;
            // "abcdd" -> a | bcdd to abcd | d
            for(int cutIdx = 1; cutIdx < len; cutIdx++){
                string leftPart = word.substr(0, cutIdx);
                string rightPart = word.substr(cutIdx); // Will go till len-1 by default.

                // cout << leftPart << endl;
                // cout << rightPart << endl;

                if(isPalindrome(leftPart)){
                    if(mp.count(rightPart) > 0) ans.push_back({mp[rightPart], i});
                }

                if(isPalindrome(rightPart)){
                    if(mp.count(leftPart) > 0) ans.push_back({i, mp[leftPart]});
                }

            }

        } 

        return ans;
    }
};
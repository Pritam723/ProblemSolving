class Solution {
public:
    bool isvalid(vector<int> &charMap, int k){
        for(int num: charMap){
            if(num >= k) return true;
        }
        return false;
    }
    int numberOfSubstrings(string s, int k) {
        int ans = 0;
        int n = s.length();

        for(int i = 0; i < n; i++){
            vector<int> charMap(26, 0);

            for(int j = i; j < n; j++){
                char ch = s[j];
                char chIdx = ch - 'a';

                charMap[chIdx]++;

                if(isvalid(charMap, k)) ans++;
            }
        }
        return ans;
    }
};
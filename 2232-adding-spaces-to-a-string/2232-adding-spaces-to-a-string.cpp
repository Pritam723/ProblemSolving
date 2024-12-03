class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        int m = spaces.size();

        string ans = "";
        int i = 0;
        int j = 0;

        while(j < m){
            if(spaces[j] == i){
                ans.push_back(' ');
                j = j + 1;
            }else{
                ans.push_back(s[i]);
                i = i + 1;
            }
        }
        while(i < n) ans.push_back(s[i++]);

        return ans;
    }
};
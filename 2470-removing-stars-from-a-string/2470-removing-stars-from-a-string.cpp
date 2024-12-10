class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        stack<char> st;
        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(ch == '*') st.pop();
            else st.push(ch);
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
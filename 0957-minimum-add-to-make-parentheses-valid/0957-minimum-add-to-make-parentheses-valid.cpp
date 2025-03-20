class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();

        stack<char> st;

        for(char ch: s){
            if(ch == '('){
                st.push(ch);
            }else{
                // So, we got ')'
                if(st.empty() or st.top() == ')'){
                    st.push(ch);
                }else{
                    st.pop();
                }
            }
        }

        return st.size();
    }
};
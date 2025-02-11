class Solution {
public:
    void process(stack<char> &st, string &part, int n){
        bool mismatchFlag = false;
        stack<char> st2;

        int i = n-1;
        while(i >= 0){
            if(part[i] == st.top()){
                st2.push(st.top());
                st.pop();
            }else{
                // So, there is a mismatch.
                mismatchFlag = true;
                break;
            }
            i--;
        }

        // We are out of the loop. So, if there is a mismatch push back all the
        // items of st2 to st.
        if(mismatchFlag == false) return;

        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }

        return;
    }
    string removeOccurrences(string s, string part) {
        int m = s.length();
        int n = part.length();
        string ans;
        stack<char> st;

        for(int i = 0; i < m; i++){
            char ch = s[i];
            st.push(ch);

            if(st.size() >= n){
                process(st, part, n);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        int start = 0, end = ans.length() - 1;

        while(start < end){
            swap(ans[start++], ans[end--]);
        }

        return ans;

    }
};
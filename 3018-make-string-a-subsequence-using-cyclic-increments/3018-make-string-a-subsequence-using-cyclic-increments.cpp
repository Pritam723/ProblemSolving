class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        int m = str1.length();
        int n = str2.length();

        while(i < m){
            char op1 = str1[i];
            char op2 = ((op1 == 'z') ? 'a' : (op1 + 1));

            char ch = str2[j];

            // Now, match them greedily.
            if(ch == op1 or ch == op2){
                i = i + 1;
                j = j + 1;
            }else{
                i = i + 1;
            }
            if(j == n) return true;
        }

        return false;
    }
};
class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int nz = 0;
        int no = 0;
        for(char ch: s){
            if(ch == '0') nz++;
            else no++;
        }

        // Config at position -1.
        int left_zero = 0;
        int right_zero = nz;

        int left_one = 0;
        int right_one = no;

        int max_score = 0;

        // Now, we go L to R.
        for(int i = 0; i < n-1; i++){
            char ch = s[i];

            if(ch == '0'){
                left_zero++;
                right_zero = nz - left_zero;
                right_one = n-i-right_zero-1;
            }else{
                left_one++;
                right_one = no - left_one;
                right_zero = n-i-right_one-1;
            }

            cout << left_zero << " " << right_one << endl;

            max_score = max(max_score, left_zero + right_one);
        }
        return max_score;
    }
};
class Solution {
public:
    int getLucky(string s, int k) {
        string t = "";
        for(char ch: s){
            int chIdx = ch - 'a' + 1;
            t = t + to_string(chIdx);
        }

        string ans = t;

        while(k > 0){
            int summ = 0;    
            int n = ans.length();
            cout << ans << endl;

            for(int i = 0; i < n; i++){
                summ = summ + ans[i] - '0';
            }

            ans = to_string(summ);

            k--;
        }

        return stoi(ans);
        // cout << t << endl;
        // return 1;
    }
};
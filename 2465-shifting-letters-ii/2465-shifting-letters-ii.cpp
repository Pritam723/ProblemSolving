class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // Refer this Video: https://www.youtube.com/watch?v=eEUjVY7wK3k
        // Explanation of difference Array: https://www.youtube.com/watch?v=ZHNVmtm08WY
        int n = s.length();

        vector<int> shiftMarker(n, 0);

        for(vector<int> shift: shifts){
            int dir = shift[2];
            int start = shift[0];
            int end = shift[1];

            if(dir == 1){
                shiftMarker[start] = shiftMarker[start] + 1;
                if(end < n-1) shiftMarker[end + 1] = shiftMarker[end + 1] - 1;
            }else{
                shiftMarker[start] = shiftMarker[start] - 1;
                if(end < n-1) shiftMarker[end + 1] = shiftMarker[end + 1] + 1;
            }
        }

        // Now take prefix from R to L side.
        int ps = 0;
        for(int i = 0; i < n ; i++){
            ps = ps + shiftMarker[i];
            int temp = abs(ps) % 26;
            if(ps < 0) temp = -temp;
            shiftMarker[i] = (temp + 26) % 26;
            // cout << shiftMarker[i] << endl;
        }

        string ans = "";

        for(int i = 0; i < n; i++){
            char ch = s[i];
            int chIdx = ch - 'a';
            chIdx = (chIdx + shiftMarker[i]) % 26;
            ch = chIdx + 'a';
            ans.push_back(ch);
        }

        return ans;
    }
};
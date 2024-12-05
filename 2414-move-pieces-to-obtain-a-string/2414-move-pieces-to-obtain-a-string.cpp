class Solution {
public:
    bool canChange(string start, string target) {
        int m = start.length();
        int n = target.length();
        int i = 0, j = 0;

        while(j < n){
            char target_ch = target[j];

            if(target_ch == '_') j++;
            else if(target_ch == 'L'){
                while(i < m && start[i] == '_') i++;
                // So, i is either m or We got a 'L' or 'R'
                if(i == m or start[i] == 'R') return false;

                // Otherwise, we got a 'L'. So, careful about the
                // Case like start = 'L_' and target = '_L'.
                if(i < j) return false;
                
                i = i + 1;
                j = j + 1;
            }else{
                // So, target_ch is 'R'.
                while(i < m && start[i] == '_') i++;
                // So, i is either m or We got a 'L' or 'R'.
                if(i == m or start[i] == 'L') return false;
                
                // Otherwise it is 'R'. But here we must be careful
                // about cases like _R and R_ where in source we got a
                // 'R' but it can't move at left.
                if(i > j) return false;
                // Otherwise we can move on.
                i = i + 1;
                j = j + 1;
            }
        }

        // Now, after j == n, we must see that rest of
        // the start[i] are '_' only.

        while(i < n) if(start[i++] != '_') return false;

        return true;
    }
};
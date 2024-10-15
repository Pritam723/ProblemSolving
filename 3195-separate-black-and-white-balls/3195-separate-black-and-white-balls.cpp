class Solution {
public:
    long long minimumSteps(string s) {
        // Strategy: Move rightmost 1s to right side so that 0s come to Left.
        // 011010011. We always need to look for group of zeros and
        // group of 1s. Start from Right. Initially zeroCount = 0.
        // Group 1 Size at left, oneCount = 2. So, movement = 0. Now again count 0s. We get 2.
        // Left of it we get oneCount = 1. So, movement = 2*1 = 2.
        // Again count zero. We get 2+1 = 3. And left of it we get 1 count = 2.
        // So steps = 3*2 = 6.Finally we have zeroCount = 4 but oneCount = 0, so
        // we stop. So, zeroCount is cumulative, oneCount is not.

        int n = s.length();
        long long ans = 0;

        int oneCount = 0;
        int zeroCount = 0;

        // Run till oneCount at left is > 0.
        int i = n-1;
        while(i >= 0 && s[i] == '1') i--; // Using this we skip all rightmost 1s.

        while(true){
            // At each step we check cumulative 0s and 1s at left.
            // First count 0s.
            while(i >= 0 && s[i] == '0'){
                zeroCount++;
                i--;
            }
            // Now count 1s at left, but make it zero first.
            oneCount = 0;
            while(i >= 0 && s[i] == '1'){
                oneCount++;
                i--;
            }

            if(oneCount == 0) break;
            ans = ans + (long long)oneCount * (long long)zeroCount;
        }
        return ans;
    }
};
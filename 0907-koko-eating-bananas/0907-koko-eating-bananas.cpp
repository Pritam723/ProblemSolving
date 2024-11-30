class Solution {
public:
    bool canFinish(vector<int>& piles, int n, int h, int k){
        int hoursTaken = 0;

        for(int pile: piles){
            int val = 0;

            if(pile % k == 0) val = pile/k;
            else val = pile/k + 1;

            hoursTaken = hoursTaken + val;

            if(hoursTaken > h) return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h){
        int n = piles.size();
        int s = 1;
        int e = INT_MIN;

        for(int pile: piles){
            e = max(e, pile);
        }

        int ans;

        while(s <= e){
            int m = s + (e-s)/2;

            if(canFinish(piles, n, h, m)){
                // So, in m speed Koko can finish the bananas within h hours.
                // Surely using speed > m she can do that too. We need to check
                // if with a lesser speed it is possible or not.
                ans = m;
                e = m - 1;
            }else{
                // So, she can not finish the bananas. We need to increase the
                // eating speed.
                s = m + 1;
            }
        }
        return ans;
    }
};
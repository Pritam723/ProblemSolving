class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        // Since we have a+b+c > 0, so answer will never be "" empty string.
        // Because we need AT MOST a occurences of 'a' & so on. So, we can
        // always have at least one character.
        // 1 Strategy can be to choose 2 from most occuring chars each time.
        // But that will fail for "aaaaaaa" and "bb". We get "aabbaa" with this strategy,
        // but actual best ans can be "aabaabaa". So, we may think choosing 2 from highest
        // and choosing 1 from next highest is better. But that will fail for "aaaaa" and "bbbbb"
        // Ans will be "aabaababb" but a better answer is "aabbaabbab". So, thisstrategy is not
        // optimal either. See 0 < a+b+c <= 300.

        // Each time we need to look for the previous 2 characters.
        priority_queue<pair<int, char>> maxPQ;

        maxPQ.push({a, 'a'});
        maxPQ.push({b, 'b'});
        maxPQ.push({c, 'c'});

        char prev1 = 'z';
        char prev2 = 'z';

        string ans = "";

        while(true){
            pair<int, char> p1 = maxPQ.top();
            maxPQ.pop();

            char ch1 = p1.second;
            int count1 = p1.first;

            if(count1 == 0) break;

            if(ch1 == prev1 && ch1 == prev2){
                // So, this char is matching with prev char. So,
                // we need to take second highest.
                pair<int, char> p2 = maxPQ.top();
                maxPQ.pop();

                char ch2 = p2.second;
                int count2 = p2.first;

                if(count2 == 0) break;
                ans.push_back(ch2);
                prev2 = prev1;
                prev1 = ch2;

                // Push back in maxPQ.
                maxPQ.push({count1, ch1});
                maxPQ.push({count2 - 1, ch2});

            }else{
                // So, we can use this ch1 only.
                ans.push_back(ch1);
                prev2 = prev1;
                prev1 = ch1;

                // Push back in maxPQ.
                maxPQ.push({count1 - 1, ch1});
            }
        }

        return ans;
    }
};
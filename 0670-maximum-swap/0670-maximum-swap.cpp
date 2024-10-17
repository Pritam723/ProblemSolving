class Solution {
public:
    int maximumSwap(int num) {
        // Swapping max number with position-0 will not do: 98368.
        // What we can do is: For each index find max at right.
        // Ex. For 9 max at right is None, same for 8.
        // For 3 max at right is 8. So, best answer is swap 3 and 8 to
        // get 98863. So, this is the answer. What if there is a clash of max?
        // Ex. 983868, see 3 has max 8 at right in 2 positions. Surely,
        // swapping with farthest 8 is better in such case.

        // Since nums size in string is 8 only, we can do a brute
        // force. But let's do using monotonic stack.

        string s = to_string(num);
        int n = s.length(); // Nums <= 10^8 , so n will be <= 8.

        // We will figure out these 2 indices and finally swap them.
        int idx1 = n-1; // The min index from Left for which we have a potential max at right.
        int idx2 = n; // The max index for idx1 with which we will swap finally.

        stack<int> st; // Will store the potential max Index. Actually no need to have a stack here
        // as we want global max at right, not local max, i.e., rightSided max. Anyway, for simplicity
        // let's use stack. Otherwise we will need to maintain 2 variables.

        for(int i = n-1; i >= 0; i--){
            int val = s[i] - '0';

            while(!st.empty() && (val > (s[st.top()] - '0'))) st.pop();

            // So, now either stack is empty or st.top() is >= val.
            // We are allowing >= because we want the farthest index maximum.
            // Take ex. 983868 see how it is better to have 988868 than 988368
            // So, actually index-3's  should not pop index-5's 8. And surely
            // index-3's right will not be potential max ever. We will always prefer
            // index-5's 8 over it.

            if(st.empty()){
                st.push(i);
                continue; // No need to do anything else.
            }
            // Otherwise we do have a have on st.top() which is >= val. (s[i]).
            // So, update idx1 and idx2.

            // But do not update if st.top() == val.
            if(val == (s[st.top()] - '0')) continue;

            idx1 = i;
            idx2 = st.top();
        }

        cout << idx1 << " " << idx2 << endl;

        if(idx2 == n) return num;
        swap(s[idx1], s[idx2]);


        return stoi(s);
    }
};
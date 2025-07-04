class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long length = 1;
        int steps = 0;
        while(length < k){
            length = length * 2;
            steps++;       
        }
        // So, after this many steps we will get length >= k.
        // if(operations.size() < steps) return -1;

        vector<int> changeVector;

        // Say length = 16 and k = 10. Since prevLength = 8 and
        // k > prevLength, so surely it was made from character (k - 8) = char 2
        // actually. And surely the impact depends on operations[steps-1].
        long long prevLength;
        long long prevK;
        while(steps > 0){
           prevLength = length / 2;
           // If k < prevLength
           if(k > prevLength){
                prevK = k - prevLength;
                // Also, what operation by which it got impacted?
                changeVector.push_back(operations[steps - 1]);
           }else{
               // Otherwise, it is generated from within the prevLength.   
                // So, no need to have any operation impact. Regardless
                // what the operation[i] is, put 0 here. (No Impact).
                changeVector.push_back(0);
           }
           // And finally we make,
        //    cout << length << " and " << k << " to " << prevLength << " and " << prevK << endl;
            length = prevLength;
            k = prevK;
            steps--;
        }

        reverse(changeVector.begin(), changeVector.end());
        char ch = 'a';
        for(int change: changeVector){
            // cout << "change is " << change << endl;
            if(change == 0) continue;
            ch = 'a' + ((ch - 'a') + 1) % 26;
        }


        return ch;
    }

};
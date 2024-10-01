class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // We need to think about the num % k values only.
        // Ex. 18 and 12 gives 3 and 2 for k = 5. So, at last mp[2]
        // should be equal to mp[3]. We need to be careful about -ve
        // numbers. -22 and 12 adds up -10 which is divisible by 5.
        // -22%5 gives -2, 12%5 = 2. So, actually we need to make -2 to -2+5 = 3.
        // cout << -22%5 << " " << -18%5 << " " << -20%5 << endl;

        // For mp[0] we just need to check if mp[0] is even.

        unordered_map<int, int> mp;

        for(int num: arr){
            int rem = num % k;
            if(rem < 0) rem = rem + k;
            mp[rem] = mp[rem] + 1;
        }

        for(pair<int, int> p: mp){
            int rem = p.first;
            int count = p.second;

            if(rem == 0){
                if(count % 2 == 1) return false;
            }else{
                // cout << "non zero case " << rem << " " << count << endl;
                if(mp[rem] != mp[k-rem]) return false;
            }
        }
        
        return true;
    }
};
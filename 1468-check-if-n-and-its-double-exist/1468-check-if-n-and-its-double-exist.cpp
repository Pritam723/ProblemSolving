class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, bool> mp;
        // Careful about the case where there is 2 no. of 0s.
        
        for(int num: arr){
            if(num == 0){
                if(mp[0] == true) return true;
                mp[0] = true;
                continue;
            }

            if(mp[num * 2] == true) return true;
            if(num % 2 == 0 and (mp[num/2] == true)) return true;
            
            mp[num] = true;
        }

        return false;
    }
};
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // sort(banned.begin(), banned.end());
        // int m = banned.size();
        int i = 1;
        unordered_map<int, bool> mp;

        for(int b: banned) mp[b] = true;
        // cout << endl;

        int summ = 0;
        int count = 0;

        // int j = 0;

        while(i <= n && summ <= maxSum){
            if(mp[i] == true){
                cout << i << " is banned" << endl;
                i = i + 1;
            }else{
                cout << "taking " << i << endl;
                summ = summ + i;
                i = i + 1;
                count = count + 1;
                cout << "Summ and count are " << summ << " and " << count << endl;
            }
        }

        if(summ > maxSum) return count - 1;
        // Otherwise it means i == n now but summ <= maxSum.
        return count;
    }
};
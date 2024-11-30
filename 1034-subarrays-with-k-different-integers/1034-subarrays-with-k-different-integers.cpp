class Solution {
public:

    int sol(vector<int>& nums, int n, int p){
        int l = 0, r = 0;
        
        int count = 0;
        unordered_map<int, int> mp;

        while(r < n){
            int add = nums[r];
            mp[add]++;

            // cout << "map size is " << mp.size() << endl;

            if(mp.size() <= p){
                // cout << "r ans l are " << r << " " << l << endl;
                count = count + (r - l + 1);
                r = r + 1;
            }else{
                // So, mp.size() has become > p.
                // Need to move the left pointer.
                while(mp.size() > p){
                    int del = nums[l];
                    mp[del]--;
                    if(mp[del] == 0) mp.erase(del);
                    l = l + 1;
                }
                // So, now we can count.
                // cout << "r ans l are " << r << " " << l << endl;

                count = count + (r - l + 1);
                r = r + 1;
            }
        }

        return count;

    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // See explanation: https://www.youtube.com/watch?v=7wYGbV_LsX4
        // The Idea is to find SAs with <= k different integers,
        // and SAs with <= k-1 different integers. And finally do sol(k-1) - sol(k).
        // We can handle k = 1 case separately.
        int n = nums.size();
        int val1 = sol(nums, n, k-1);
        int val2 = sol(nums, n, k);

        // cout << val1 << " " << val2 << endl;

        return val2 - val1;
    }
};
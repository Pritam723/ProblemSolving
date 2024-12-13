class Comp{
    public:
    bool operator()(pair<int, int> p1, pair<int, int> p2){
        if(p1.first > p2.first) return true;
        else if(p1.first == p2.first) return p1.second > p2.second;
        return false;
    }
};

class Solution {
public:

    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> minPQ;
        
        for(int i = 0; i < n; i++){
            minPQ.push(make_pair(nums[i], i));
        }

        while(!minPQ.empty()){
            pair<int,int> topItem = minPQ.top(); minPQ.pop();
            
            
            int idx = topItem.second;
            int val = nums[idx];

            cout << idx << " having value " << val << endl;

            if(val == 0) continue;
            ans = ans + (long long)(val);
            
            int leftIdx = idx-1;
            int rightIdx = idx+1;

            if(leftIdx >= 0) nums[leftIdx] = 0;
            if(rightIdx < n) nums[rightIdx] = 0;
        }

        return ans;
    }
};
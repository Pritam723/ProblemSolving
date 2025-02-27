class Solution {
public:
vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int n = nums.size();
    int mx = pow(2,maximumBit)-1;
    vector<int> ans(n,0);
    int xr = 0;
    for(int i=0;i<n;i++)
    {
        xr ^= nums[i]; 
        ans[n-i-1] = (mx)^(xr&mx);
    }
    return ans;  
}
};
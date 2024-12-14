class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        int size=nums.size();
        long long  startindex=0;
        pair<long ,long > maxi={nums[0],0};pair<long ,long >mini={nums[0],0};
        long long  windowsize=1;
        for(int i=1;i<size && startindex<size;i++){//O(size of nums)
            long long  a=abs(maxi.first-nums[i]);
            long long  b=abs(mini.first-nums[i]);
            if( a<=2 &&  b<=2){
                windowsize++;
                if(nums[i]>=maxi.first){maxi.first=nums[i],maxi.second=i;}
                if(nums[i]<=mini.first){mini.first=nums[i],mini.second=i;}
            }
            else{
                long long  sub_array=((windowsize-1)*(windowsize))/2;
                
                ans+=sub_array;
                if(windowsize==1){startindex=i;}
                else{
                    if(a>2){
                        ans-=((abs(i-maxi.second-1)*abs(i-maxi.second-2))/2);
                        startindex=maxi.second+1;i=startindex;}
                    if(b>2){
                        ans-=((abs(i-mini.second-1)*abs(i-mini.second-2))/2);
                        startindex=mini.second+1;i=startindex;}
                }
                maxi.first=nums[startindex],mini.first=nums[startindex];
                maxi.second=mini.second=startindex;
                windowsize=1;
            }
        }
        long long  x=((windowsize-1)*(windowsize))/2;
        //Time Complexity:O(n)
        //Space Complexity:O(1)
       
        ans+=(size+x);
        return ans;
        
    }
};
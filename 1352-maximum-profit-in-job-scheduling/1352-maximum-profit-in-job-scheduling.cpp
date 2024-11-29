class Job{
    public:
    int s;
    int e;
    int p;

    Job(int s, int e, int p){
        this->s = s;
        this->e = e;
        this->p = p;
    }
};

class Solution {
public:

    int lowerBound(vector<Job> &jobs, int n, int x) {
        // Write your code here
        // int n = arr.size();

        if(x > jobs[n-1].s) return n;

        int start = 0;
        int end = n-1;
        
        int ans;

        while(start <= end){
            int mid = start + (end-start)/2;

            int val = jobs[mid].s;

            if(x > val){
                // So, our desired index must be at right.
                start = mid + 1;
            }else{
                // So, val >= x. So, it is a potential ans.
                ans = mid;
                end = mid - 1;
            }
        }

        return ans;
    }

    static bool comp(Job j1, Job j2){
        return j1.s < j2.s;
    }
    int sol(vector<Job> &jobs, int n, int i, vector<int> &dp){
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        Job j = jobs[i];

        // Now, we have choice to either include j or exclude j.
        int excl = sol(jobs, n, i+1, dp);

        // If we want to include, then skip till we find next start time which
        // is >= this endTime.

        int endTime = j.e;

        // int k = i;
        // while(k < n && jobs[k].s < endTime) k++;
        
        int k = lowerBound(jobs, n, endTime);

        // So, we got that next job.

        int incl = j.p + sol(jobs, n, k, dp);

        dp[i] = max(incl, excl);

        return dp[i];

    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Job> jobs;
        for(int i = 0; i < n; i++){
            jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
        }

        sort(jobs.begin(), jobs.end(), comp);
        
        vector<int> dp(n+1, -1);

        int i = 0;

        int ans = sol(jobs, n, i, dp);

        return ans;
    }
};
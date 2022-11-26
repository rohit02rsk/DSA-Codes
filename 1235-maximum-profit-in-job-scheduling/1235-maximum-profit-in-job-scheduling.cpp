class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    
    int getNextJob(vector<vector<int>>& jobs, int idx, const int& n) {
        for(int i=idx+1; i<n; i++)
        {
            if(jobs[idx][1] <= jobs[i][0]) return i;
        }
        return n;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));

        for(int i=0; i<n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }

        sort(jobs.begin(), jobs.end(), compare);

        vector<int> dp(n+1, 0);
        dp[n-1] = jobs[n-1][2];
        for(int i=n-1; i>=0; i--) {
            int next = getNextJob(jobs, i, n);  
            int incl = dp[next] + jobs[i][2];
            int excl = dp[i+1];
            dp[i] = max(incl, excl);
        }
        return dp[0];
    }
};
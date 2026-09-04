class Solution {
public:
    
    int solve(int i,vector<vector<int>>& jobs, vector<int>& start, vector<int>& dp, int n ){
        if(i>=n)return 0;

        if(dp[i]!=-1)return dp[i];

        int skip = solve(i+1,jobs,start,dp,n);

        int next = lower_bound(start.begin(),start.end(),jobs[i][1]) - start.begin();

        int take = jobs[i][2] + solve(next,jobs,start,dp,n);

        return dp[i] = max(skip,take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = profit.size();
        vector<vector<int>> jobs;

        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }

        sort(jobs.begin(),jobs.end());

        vector<int> start;
        for(auto job:jobs){
            start.push_back(job[0]);
        }

        vector<int> dp(n,-1);

        return solve(0,jobs,start,dp,n);
        
    }
};
class Solution {
public:
    int findMaxProfit(vector<vector<int>>& jobs, vector<int>& start, int n, int position, vector<int>& dp){
        if(position == n){
            return 0;
        }
        
        if(dp[position]!=-1){
            return dp[position];
        }
        
        int nextIndex = lower_bound(start.begin(), start.end(), jobs[position][1]) - start.begin();
        int maxProfit = max(findMaxProfit(jobs, start, n, position+1, dp), jobs[position][2] + findMaxProfit(jobs,start,n,nextIndex, dp));
        
        return dp[position] = maxProfit;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        
        for(int i = 0; i<startTime.size();i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        vector<int> dp(profit.size() + 1, -1);
        
        sort(jobs.begin(), jobs.end());
        
        int n = profit.size();
        
        dp[n] = 0;
        
        for(int i = 0; i < profit.size() ; i++){
            startTime[i] = jobs[i][0];
        }
        
        for(int position = n-1; position >= 0; position--){
            int nextIndex = lower_bound(startTime.begin(), startTime.end(), jobs[position][1]) - startTime.begin();
            int maxProfit = max(dp[position+1], jobs[position][2] + dp[nextIndex]);
        
            dp[position] = maxProfit;
        }
        
        return dp[0];
    }
};
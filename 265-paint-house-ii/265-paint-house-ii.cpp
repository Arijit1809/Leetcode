class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int m = costs[0].size();
        vector<vector<int>> memo(n+1,vector<int>(m,-1));
        for(int i = 0;i<m;i++){
            memo[0][i]=costs[0][i];
        }
        for(int i = 1;i<n;i++){
            int minPrice = INT_MAX;
            for(int j = 0;j<m;j++){
                int cost = INT_MAX;
                for(int k = 0;k<m;k++){
                    if(k==j) continue;
                    cost = min(cost,costs[i][j]+memo[i-1][k]);
                }
                memo[i][j]=cost;
            }
        }
        int ans = INT_MAX;
        for(int i = 0;i<m;i++){
            ans=min(ans,memo[n-1][i]);
        }
        return ans;
    }
};
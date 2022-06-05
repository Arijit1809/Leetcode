typedef vector<vector<int>> vvi;
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int houses = costs.size();
        int colors = costs[0].size();
        vvi dp(houses+1,vector<int>(colors));
        for(int i = 0; i< colors;i++){
            dp[0][i] = 0;
        }
            
        for(int j=1;j<=houses;j++){
            for(int i = 0;i<colors;i++){
                int minCost = INT_MAX;
                for(int k = 0;k<colors;k++){
                    if(k==i) continue;
                    minCost = min(minCost, costs[j-1][k] + dp[j-1][k]);
                }
                dp[j][i] = minCost;
            }
        }
        int ans = INT_MAX;
        for(int i = 0;i < colors;i++){
            ans = min(ans,dp[houses][i]);
        }
        return ans;
    }
};
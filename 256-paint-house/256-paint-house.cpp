typedef vector<vector<int>> vvi;
class Solution {
private:
    // vvi dp;
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
        return min({dp[houses][0],dp[houses][1],dp[houses][2]});
    }
    // int rec2(vvi& costs,int index, int color){
    //     // if(index<0) return 0; //initialised in tabulation
    //     if(dp[index+1][color]!=-1) return dp[index+1][color];
    //     int minCost = INT_MAX;
    //     for(int i = 0; i < costs[0].size(); i++){ //putting this in the tabulation with variable k
    //         if(i == color){
    //             continue;
    //         }
    //         minCost = min(minCost, costs[index][i] + rec2(costs,index-1,i));
    //     }
    //     return dp[index+1][color] = minCost;
    // }
};
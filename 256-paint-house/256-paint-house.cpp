typedef vector<vector<int>> vvi;
class Solution {
private:
    vvi dp;
public:
    int minCost(vector<vector<int>>& costs) {
        int houses = costs.size();
        int colors = costs[0].size();
        dp.resize(houses+1,vector<int>(colors,-1));
        for(int i = 0; i< colors;i++){
            dp[0][i] = 0;
        }
        int minCost = INT_MAX;
        for(int i = 0;i<colors;i++){
            minCost = min(minCost,rec2(costs,houses-1,i));
            // for(int j = 0; j < houses ; j++){ //this is new, this is replacing the recursion
            //     for(int k = 0; k < colors; k++){
            //         if(k==i) continue;
            //         dp[j+1][k] = min(dp[j+1][k], )
            //     }
            // }
        }
        return minCost;
    }
    int rec2(vvi& costs,int index, int color){
        // if(index<0) return 0; //initialised in tabulation
        if(dp[index+1][color]!=-1) return dp[index+1][color];
        int minCost = INT_MAX;
        for(int i = 0; i < costs[0].size(); i++){ //putting this in the tabulation with variable k
            if(i == color){
                continue;
            }
            minCost = min(minCost, costs[index][i] + rec2(costs,index-1,i));
        }
        return dp[index+1][color] = minCost;
    }
};
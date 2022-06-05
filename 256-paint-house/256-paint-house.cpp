typedef vector<vector<int>> vvi;
class Solution {
    private:
    vvi dp;
public:
    int minCost(vector<vector<int>>& costs) {
        int houses = costs.size();
        int colors = costs[0].size();
        dp.resize(houses+1,vector<int>(colors,-1));
        int minCost = INT_MAX;
        for(int i = 0;i<colors;i++){
            minCost = min(minCost,rec2(costs,houses-1,i));
        }
        return minCost;
    }
    
    int rec2(vvi& costs,int index, int color){
        if(index<0) return 0;
        if(dp[index+1][color]!=-1) return dp[index+1][color];
        int minCost = INT_MAX;
        for(int i = 0; i < costs[0].size(); i++){
            if(i == color){
                continue;
            }
            minCost = min(minCost, costs[index][i] + rec2(costs,index-1,i)); //i color was used to paint this house
        }
        return dp[index+1][color] = minCost;
    }
};
typedef vector<vector<int>> vvi;
class Solution {
private:
    vvi dp;
public:
    int minCost(vector<vector<int>>& costs) {
        int houses = costs.size();
        int colors = costs[0].size();
        dp.resize(houses+1,vector<int>(colors+1,-1));
        return rec(costs,costs.size()-1,-1);
    }
    
    int rec(vvi& costs,int index, int color){
        if(dp[index+1][color+1]!=-1) return dp[index+1][color+1];
        if(index<0) return dp[index+1][color+1] = 0;
        int minCost = INT_MAX;
        for(int i = 0; i < costs[0].size(); i++){
            if(i == color){
                continue;
            }
            minCost = min(minCost, costs[index][i] + rec(costs,index-1,i)); //i color was used to paint this house
        }
        return dp[index+1][color+1] = minCost;
    }
};
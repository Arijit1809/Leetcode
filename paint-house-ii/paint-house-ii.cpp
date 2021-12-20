class Solution {
public:
    vector<vector<int>> memo;
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(),m=costs[0].size();
        memo.resize(n+1,vector<int>(m+1,-1));
        return dp(0,0,costs);
    }
    int dp(int index,int prevColorIdx,vector<vector<int>>& costs){
        if(index==costs.size()) return 0;
        if(memo[index][prevColorIdx]!=-1) return memo[index][prevColorIdx];
        int minPrice = INT_MAX;
        for(int i = 0;i<costs[0].size();i++){
            if(i==prevColorIdx-1) continue;
            minPrice = min(minPrice,costs[index][i]+dp(index+1,i+1,costs));
        }
        return memo[index][prevColorIdx] = minPrice;
    }
};
// class Solution {
// public:
//     int memo[101][4];
//     int minCost(vector<vector<int>>& costs) {
//         memset(memo,-1,sizeof(memo));
//         return dp(0,0,costs);
//     }
//     int dp(int index,int prevColorIdx,vector<vector<int>>& costs){
//         if(index==costs.size()) return 0;
//         if(memo[index][prevColorIdx]!=-1) return memo[index][prevColorIdx];
//         int minPrice = INT_MAX;
//         for(int i = 0;i<costs[0].size();i++){
//             if(i==prevColorIdx-1) continue;
//             minPrice = min(minPrice,costs[index][i]+dp(index+1,i+1,costs));
//         }
//         return memo[index][prevColorIdx] = minPrice;
//     }
// };
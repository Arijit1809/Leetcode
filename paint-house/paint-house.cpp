class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
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
        // for(int i =0;i<n;i++){
        //     for(int j = 0;j<m;j++){
        //         cout<<memo[i][j]<<" ";
        //     }cout<<endl;
        // }
        return min({memo[n-1][0],memo[n-1][1],memo[n-1][2]});
    }
    // int dp(int index,int prevColorIdx,vector<vector<int>>& costs){
    //     if(index==costs.size()) return 0;
    //     if(memo[index][prevColorIdx]!=-1) return memo[index][prevColorIdx];
    //     int minPrice = INT_MAX;
    //     for(int i = 0;i<3;i++){
    //         if(i==prevColorIdx-1) continue;
    //         minPrice = min(minPrice,costs[index][i]+dp(index+1,i+1,costs));
    //     }
    //     return memo[index][prevColorIdx] = minPrice;
    // }
};
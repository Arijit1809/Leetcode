typedef vector<vector<int>> vvi;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vvi dp(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        int n = grid.size(), m = grid[0].size();
        
        for(int i = n ; i >= 0; i--){
            for(int j = m ;j>=0;j--){
                if(i==n || j==m){ 
                    dp[i][j] = INT_MAX;
                    continue;
                }else if(i==n-1 && j==m-1){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int goDown = dp[i+1][j];
                int goRight = dp[i][j+1];
                dp[i][j] = grid[i][j] + min(goRight,goDown);
            }
        }
        return dp[0][0];
    }
};
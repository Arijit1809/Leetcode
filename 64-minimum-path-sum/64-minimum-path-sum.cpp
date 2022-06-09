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
        // return dfs(grid,0,0,grid.size(),grid[0].size(),memo);
        
    }
    
    // int dfs(vvi& grid, int row, int col, int n, int m, vvi& memo){
    //     if(row==n || col == m){
    //         return INT_MAX;
    //     }
    //     if(row==n-1 && col==m-1){
    //         return grid[n-1][m-1];
    //     }
    //     if(memo[row][col]!=-1) return memo[row][col];
    //     int goDown = INT_MAX, goRight = INT_MAX;
    //     goDown =  dfs(grid,row+1,col,n,m,memo);
    //     goRight =  dfs(grid,row,col+1,n,m,memo);
    //     return memo[row][col] = grid[row][col] + min(goDown,goRight);
    // }
};
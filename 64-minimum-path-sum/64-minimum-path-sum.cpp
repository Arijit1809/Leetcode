typedef vector<vector<int>> vvi;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vvi memo(grid.size(),vector<int>(grid[0].size(),-1));
        return dfs(grid,0,0,grid.size(),grid[0].size(),memo);
    }
    
    int dfs(vvi& grid, int row, int col, int n, int m, vvi& memo){
        if(row==n-1 && col==m-1){
            return grid[n-1][m-1];
        }
        if(memo[row][col]!=-1) return memo[row][col];
        int goDown = INT_MAX, goRight = INT_MAX;
        if(row<n-1){
            goDown = grid[row][col] + dfs(grid,row+1,col,n,m,memo);
        }
        if(col<m-1){
            goRight = grid[row][col] + dfs(grid,row,col+1,n,m,memo);
        }
        return memo[row][col] = min(goDown,goRight);
    }
};
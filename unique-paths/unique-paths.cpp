class Solution {
public: 
    int dp[101][101];
    int uniquePaths(int m, int n) {
        return dfs(m - 1, n - 1);
    }
    
    int dfs(int m, int n) {
        if (m < 0 || n < 0) {
          return 0;
        }else if (m == 0 || n == 0) {
          return 1;
        }else if(dp[m][n]>0){
            return dp[m][n];
        }else {
          return dp[m][n] = dfs(m - 1, n) + dfs(m, n - 1);
        }
    }
};
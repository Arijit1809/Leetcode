class Solution {
public:
      vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), 0));
        vector<vector<int>> res=dp;
        for(int i=0;i<dp.size();i++) {
            if(i==0) dp[0][0]=mat[0][0];
            else dp[i][0]=mat[i][0]+dp[i-1][0];
            for(int j=1;j<dp[0].size();j++) {
                if(i==0) dp[i][j]=dp[i][j-1]+mat[i][j];
                else dp[i][j]=dp[i-1][j]-dp[i-1][j-1]+dp[i][j-1]+mat[i][j];
            }
        }
        for(int i=0;i<dp.size();i++) {
            for(int j=0;j<dp[0].size();j++) {
                int ux=max(0, i-K), uy=max(0, j-K), m=mat.size()-1, n=mat[0].size()-1;
                int dx=min(m, i+K), dy=min(n, j+K), cur=dp[dx][dy];
                if(uy>0) cur-=dp[dx][uy-1];
                if(ux>0) cur-=dp[ux-1][dy];
                if(uy>0&&ux>0) cur+=dp[ux-1][uy-1];
                res[i][j]=cur;
            }
        }
        return res;
    }
};
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int trans = k;
        int len = prices.size();
        vector<vector<vector<int>>> dp(len+1, vector<vector<int>>(2, vector<int>(trans+1, 0)));
        for(int i = len-1; i>=0; i--){
            for(int j = 0; j <= 1; j++){
                for(int k = 1; k <= trans; k++){
                    if(j == 0){
                        int buy = dp[i+1][1][k] - prices[i];
                        int notBuy = dp[i+1][0][k];
                        
                        dp[i][j][k] = max(buy, notBuy);
                    }else{
                        int sell = dp[i+1][0][k-1] + prices[i]; 
                        int notSell = dp[i+1][1][k];
                        
                        dp[i][j][k] = max(sell, notSell);
                    }
                }
            }
        }
        return dp[0][0][trans];
    }
};
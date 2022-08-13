class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int trans = 2;
        int len = prices.size();
        vector<vector<vector<int>>> dp(len+1, vector<vector<int>>(2, vector<int>(trans+1, 0)));
        //already trans = 0 wala dp sab 0 hai
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
        return dp[0][0][2];
        // return rec(prices, 0, 0, trans, dp);
    }
    
    int rec(vector<int>& prices, int index, int prev, int trans, vector<vector<vector<int>>>& dp){
        int len = prices.size();
        if(index==len || trans==0) return 0;
        if(dp[index][prev][trans]!=-1) return dp[index][prev][trans];
        if(prev==0){
            int buy = rec(prices, index+1, 1, trans,dp) - prices[index];
            int notBuy = rec(prices, index+1, 0, trans, dp);
            return dp[index][prev][trans] = max(buy, notBuy);
        }else{
            int sell = prices[index] + rec(prices, index+1, 0, trans - 1, dp);
            int notSell = rec(prices, index+1, 1, trans, dp);
            return dp[index][prev][trans] = max(sell, notSell);
        }
    }
};
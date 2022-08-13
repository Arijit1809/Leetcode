class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int trans = 2;
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(trans+1, -1)));
        
        return rec(prices, 0, 0, trans, dp);
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
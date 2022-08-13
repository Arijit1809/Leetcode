  class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, l = 0, r = 1;
        while(r < prices.size()){
            if(prices[r] < prices[l]){
                l = r;
            }else{
                while(r+1 < prices.size() and prices[r+1] > prices[r]){r++;}
                profit+=prices[r]-prices[l];
                l = r+1;
            }
            r++;
        }
        return profit;
    }
};
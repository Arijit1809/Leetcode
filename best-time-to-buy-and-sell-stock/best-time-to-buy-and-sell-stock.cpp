class Solution {
public:
    int maxProfit(vector<int>& p) {
        int min = INT_MAX;
        int profit = 0;
        for(int i =0;i<p.size();i++){
            if(p[i]<min){
                min = p[i];
            }
            if(p[i]>min){
                profit=max(profit,p[i]-min);
            }
        }
        return profit;
    }
};
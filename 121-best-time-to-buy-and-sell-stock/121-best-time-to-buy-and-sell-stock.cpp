class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mini = INT_MAX;
        int profit = 0;
        for(int i =0;i<p.size();i++){
            if(p[i]<mini){
                mini = p[i];
            }
            if(p[i]-mini>profit){
                profit=p[i]-mini;
            }
        }
        return profit;
    }
};
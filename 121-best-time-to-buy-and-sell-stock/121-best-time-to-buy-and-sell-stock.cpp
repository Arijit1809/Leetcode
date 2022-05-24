class Solution {
public:
    int maxProfit(vector<int>& p) {
        int minS=p[0],maxS=p[0];
        int profit = 0;
        for(int i = 1;i<p.size();i++){
            if(p[i]>minS){
                profit = max(profit,p[i]-minS);
            }
            minS = min(p[i],minS);
        }
        return profit;
    }
};
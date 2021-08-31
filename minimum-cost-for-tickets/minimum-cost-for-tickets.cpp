class Solution {
public:
    vector<int> dp;
    int min3(int a,int b,int c){
        return min(min(a,b),c);
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        dp.resize(367);
        return mincost(days, costs,0);
        
    }
    int mincost(vector<int>& days, vector<int>& costs,int index){
        if(index>=days.size()) return 0;
        if(dp[index]) return dp[index];
        int i=index,i7=0,i30=0;
        while(i<days.size()) {
            if(days[i]<days[index]+7) i7 = i;
            if(days[i]<days[index]+30) i30=i;
            i++;
        }
        int cost_day = mincost(days,costs,index+1)+costs[0];
        int cost_week = mincost(days,costs,i7+1)+costs[1];
        int cost_month = mincost(days,costs,i30+1)+costs[2];
        dp[index] = min3(cost_day,cost_week,cost_month);
        
        return dp[index];
    }
};
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int costDel = 0;
        for(int i =0;i<s.length();i++){
            if(s[i]==s[i+1]){
                char temp = s[i];
                int maxCost=0,removalCost=0;
                while(s[i]==temp){
                    maxCost=max(maxCost,cost[i]);
                    removalCost+=cost[i];
                    i++;
                }
                i--;
                removalCost-=maxCost;
                costDel+=removalCost;
            }
        }
        return costDel;
    }
};
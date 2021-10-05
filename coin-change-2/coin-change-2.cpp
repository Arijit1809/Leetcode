class Solution {
public:
    vector<vector<int>> dp;
    int change(int amount, vector<int>& coins) {
        dp.resize(amount+1,vector<int>(coins.size()+1,-1));
        return noOfCoins(amount,coins,0);
    }
    
    int noOfCoins(int amount, vector<int>& coins,int position){
        if(position>=coins.size()) return 0;
        if(amount==0 || amount<0) return amount==0?1:0;
        
        if(dp[amount][position]!=-1) return dp[amount][position];
        
        int includePosition = noOfCoins(amount-coins[position],coins,position);
        int notIncludePosition = noOfCoins(amount,coins,position+1);
        
        return dp[amount][position] = includePosition+notIncludePosition;
    }
};
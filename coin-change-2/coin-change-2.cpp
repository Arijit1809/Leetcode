class Solution {
public:
    
    vector<vector<int>> memo;
    
    int change(int amount, vector<int>& coins){
        memo.resize(amount+1,vector<int>(coins.size()+1,-1));
        return rec(amount,coins,0);
    }
    
    int rec(int amount,vector<int>& coins,int start){
        
        if(amount<0) return 0;
        if(amount==0) return 1;

        if(memo[amount][start]!=-1) return memo[amount][start];
        
        for(int i =start;i<coins.size();i++){
            return memo[amount][start] = rec(amount-coins[i],coins,start)+rec(amount,coins,start+1);
        }
        
        return memo[amount][start] = 0;
        
    }
    
};
class Solution {
public:
    vector<long long> dp;
    
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.resize(n,-1);
        return rec(questions,0);
    }
    
    long long rec(vector<vector<int>>& questions,int index){
        int n = questions.size();
        if(index>=n) return 0;
        if(dp[index]!=-1) return dp[index];
        long long maxScore =0;
        maxScore = max(questions[index][0]+rec(questions,1+index+questions[index][1]),rec(questions,index+1));
        return dp[index] = maxScore;
    }
};
class Solution {
public:
   int dp[20][20];

     int solve(vector<int>&nums ,int i,int j){
     if(i==j) return nums[i];
     
     if(i>j){
       return 0;
     }
     if(dp[i][j]!=-1) return dp[i][j];
     
     int o1 = nums[i]+ min( solve(nums,i+2,j),solve(nums,i+1,j-1));
     int o2 = nums[j] + min(solve(nums,i,j-2),solve(nums,i+1,j-1));
     
     return dp[i][j]= max(o1,o2);   
   }
  
    bool PredictTheWinner(vector<int>& nums) {
    memset(dp,-1,sizeof(dp));
       int sum =accumulate(nums.begin(),nums.end(),0);
        int o1=solve(nums,0,nums.size()-1);
      if(o1>=(sum-o1)) return true;
      return false;
      
     
    }
};
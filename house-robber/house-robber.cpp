class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return robSim(0,nums);
    }
    
    int robSim(int index, vector<int>& nums){
        if(index>nums.size()-1){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int stealPreHouse = nums[index]+robSim(index+2,nums);
        int stealPostHouse=robSim(index+1,nums);
        return dp[index] = max(stealPreHouse,stealPostHouse);
    }
};
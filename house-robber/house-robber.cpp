class Solution {
private:
    vector<int> dp;
public:
    
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return max(robHelper(nums,0),robHelper(nums,1));
    }
    
    int robHelper(vector<int>& nums, int start){
        if(start>nums.size()-1) return 0;
        if(dp[start]!=-1) return dp[start];
        int maxMoney = 0;
        int robAtGapOne = robHelper(nums,start+2);
        int robAtGapTwo = robHelper(nums,start+3);
        return dp[start] = nums[start] + max(robAtGapOne,robAtGapTwo);
    }
};
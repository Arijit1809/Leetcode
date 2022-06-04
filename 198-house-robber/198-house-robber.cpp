class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1,-1);
        return max(rec(nums,n-1),rec(nums,n-2));
    }
    
    int rec(vector<int>& nums, int index){
        if(dp[index+1]!=-1) return dp[index+1];
        if(index<0) return 0;
        if(index==0) return nums[0];
        if(index==1) return nums[1];
        int skip_one = rec(nums,index-2);
        int skip_two = rec(nums,index-3);
        return dp[index+1] = nums[index] + max(skip_one,skip_two);
    }
};
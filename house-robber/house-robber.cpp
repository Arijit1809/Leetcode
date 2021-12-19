class Solution {
public:
	int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
		vector<int> dp(n);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i = 2;i<n;i++){
            dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
        }
        return max(dp[n-1],dp[n-2]);
	}
};
static int x = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	cout.tie(NULL);
	return 0;
}();
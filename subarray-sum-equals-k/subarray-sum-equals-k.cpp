class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
	int ans = 0;
	unordered_map<int, int> sumCnt;
	sumCnt[0]++;
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += nums[i];
		if (sumCnt.count(sum - k)) ans += sumCnt[sum-k];
		sumCnt[sum]++;
	}
	return ans;
    }
};
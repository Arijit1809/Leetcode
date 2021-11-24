class Solution {
public:
    int longestSubarray(vector<int>& nums){
	int left =0,right = 0,count= 0,result=0,n=nums.size();
	for(right;right<n;right++){
		if(nums[right]==0){
			count++;
		}
		while(count>1){
			if(nums[left++]==0) count--;
		}
		result = max(result,right-left);
	}
	return result;
}
};
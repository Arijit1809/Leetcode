class Solution {
public:
int firstMissingPositive(vector<int>& nums) {
int n=nums.size(),i=0;
while(i<n){
if(nums[i]==i+1||nums[i]<=0||nums[i]>n)
i++;
else if(nums[nums[i]-1]!=nums[i]){
swap(nums[i],nums[nums[i]-1]);
}
else
i++;
}
for(i=0;i<n;i++){
if(nums[i]!=i+1)
break;
}
return i+1;
}
};
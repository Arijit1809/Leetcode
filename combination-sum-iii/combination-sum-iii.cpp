class Solution {
public:
    vector<vector<int>> noOfSums;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums(9);
        for(int i = 1 ; i <= 9 ; i++){
            nums[i-1]=i;
        }
        // for(auto i : nums) cout<<i<<" ";
        vector<int> result;
        combination(nums,result,k,n,0);
        return noOfSums;
    }
    void combination(vector<int>& nums, vector<int> result,int k,int n,int index){
        //base conditions
        if(result.size()==k && n==0){
            noOfSums.push_back(result);
            return;
        }
        if(result.size()==k && n!=0) return;    
        if(index == nums.size() || n<=0) return;
        
        //consider the element at index 
        result.push_back(nums[index]);
        combination(nums,result,k,n-nums[index],index+1);
        //backtrack
        result.pop_back();
        //not consider
        combination(nums,result,k,n,index+1);
    }
};
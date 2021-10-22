class Solution {
public:
    
    int calculateOrSum(int num1,int num2){
        return num1|num2;
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        // int maxOR = accumulate(nums.begin(),nums.end(),0,calculateOrSum);
        int maxOR=0;
        for(int &num:nums) maxOR|=num;
        return dfs(nums,0,0,maxOR);
    }
    
    int dfs(vector<int>& nums,int orValue,int atIndex,int maxOR){
        
        if(atIndex==nums.size() && orValue == maxOR) return 1;
        
        if(atIndex==nums.size()) return 0;
        
        for(int &num:nums){
            return dfs(nums,orValue|nums[atIndex],atIndex+1,maxOR) + dfs(nums,orValue,atIndex+1,maxOR);
        }
        
        if(orValue==maxOR){        
            return 1;                
        }
        
        return 0;
    }
};
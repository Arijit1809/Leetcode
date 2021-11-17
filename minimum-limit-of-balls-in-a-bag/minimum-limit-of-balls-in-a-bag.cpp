class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int lo = 1;
        int hi = 1e9;
        int mid = 0;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            int currMaxOperations = 0;
            for(int i =0;i<nums.size();i++){
                currMaxOperations += (nums[i]-1)/mid; 
            }
            if(currMaxOperations>maxOperations){
                lo=mid+1;
            }else{
                hi=mid;
            } 
        }
        return lo;
    }
};
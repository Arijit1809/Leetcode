class Solution {
public:
    
    vector<int> searchRange(vector<int>& nums, int target) {
        pair<vector<int>::iterator,vector<int>::iterator> bounds = equal_range(nums.begin(), nums.end(), target);
        vector<int> ans = {-1,-1};
        if (bounds.first == bounds.second)
            return {-1, -1};
        ans[0]=bounds.first - nums.begin();
        ans[1]=bounds.second - nums.begin() - 1;
        return ans;
    }
    
    
};
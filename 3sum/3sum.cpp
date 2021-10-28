class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int  len = nums.size();
        if (len < 3)
            return {};
        
        std::sort(nums.begin(), nums.end());
        
        std::set<vector<int>> ans;
        
        for(int i = 0; i < len - 2; i++) {
            
            int j = i + 1;
            int k = len - 1;
            
            while (j < k) {
            
                const int sum = nums[i] + nums[j] + nums[k];
                
                if (0 == sum) {
                    ans.insert({nums[i], nums[j++], nums[k--]});
                }
                else if (0 > sum)
                    j++;
                else if (0 < sum)
                    k--;
            }
        }
        
        vector<vector<int>> res;
        
        std::copy(
            ans.begin(), ans.end(),
            std::back_inserter(res));
        
        return res;
    }
};
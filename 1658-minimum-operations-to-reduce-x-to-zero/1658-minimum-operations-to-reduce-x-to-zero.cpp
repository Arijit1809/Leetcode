class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int current = 0;
        for (int num : nums) {
            current += num;
        }
        int n = nums.size();
        int mini = INT_MAX;
        int left = 0;

        for (int right = 0; right < n; right++) {
            // sum([0,..,left) + (right,...,n-1]) = x
            current -= nums[right];
            // if smaller, move `left` to left
            while (current < x && left <= right) {
                current += nums[left];
                left += 1;
            }
            // check if equal
            if (current == x) {
                mini = min(mini, (n - 1 - right) + left);
            }
        }
        return mini != INT_MAX ? mini : -1;
    }
};
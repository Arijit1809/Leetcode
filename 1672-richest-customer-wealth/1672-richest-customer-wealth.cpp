class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        // Initialize the maximum wealth seen so far to 0 (the minimum wealth possible)
        int maxWealthSoFar = 0;
        
        // Iterate over accounts
        for (vector<int>& account : accounts) {
            // For each account, initialize the sum to 0
            int currCustomerWealth = 0;
            // Add the money in each bank
            for (int money : account) {
                currCustomerWealth += money;
            }
            // Update the maximum wealth seen so far if the current wealth is greater
            // If it is less than the current sum
            maxWealthSoFar = max(maxWealthSoFar, currCustomerWealth);
        }
        
        // Return the maximum wealth
        return maxWealthSoFar;
    }
};
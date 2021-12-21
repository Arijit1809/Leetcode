class Solution {
public:
    int largestUniqueNumber(vector<int> &A) {
        unordered_map<int, int> count;
        for (int &i : A) {
          count[i]++;
        }
        int result = -1;
        for (auto &[key, val] : count) {
            if (val == 1) {
              result = max(result, key);
            }
        }
        return result;
    }
};
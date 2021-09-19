class Solution {
public:
   int countKDifference(vector<int>& nums, int k) {
    int cnt[201] = {}, res = 0;
    for (auto n : nums)
        ++cnt[n];
    for (int i = k + 1; i < 201; ++i)
        res += cnt[i] * cnt[i - k];
    return res;
}
};
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& n) {
    int left = 0, right = accumulate(begin(n), end(n), 0), sz = n.size();
    for (int i = 0; i < sz; ++i) {
        right -= n[i];
        left += n[i];
        n[i] = right - n[i] * (sz - i - 1) - left + n[i] * (i + 1);
    }
    return n;
}
};
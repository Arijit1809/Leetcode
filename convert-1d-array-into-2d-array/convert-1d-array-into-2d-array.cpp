class Solution {
public:
vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    vector<vector<int>> res;
    if (m * n == original.size())
        for (auto i : original) {
            if (res.empty() || res.back().size() == n)
                res.push_back({});
            res.back().push_back(i);
        }
    return res;
}
};
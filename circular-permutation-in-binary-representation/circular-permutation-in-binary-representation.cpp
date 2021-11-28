class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
    vector<int> res;
    for (int i = 0; i < 1 << n; ++i)
        res.push_back(start ^ i ^ i >> 1); //here the i^(i>>1) is the part that generates ith gray code number.
    return res;
}
};
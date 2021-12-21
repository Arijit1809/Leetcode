class Solution {
public:
    int numOfStrings(vector<string>& ps, string word) {
    return count_if(begin(ps), end(ps), [&](const auto &p) { return word.find(p) != string::npos; });
}
};
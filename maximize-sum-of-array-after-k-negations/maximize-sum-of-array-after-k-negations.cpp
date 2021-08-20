class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
  int cnt[201] = {}, j = -100;
  for (auto i : A) ++cnt[i + 100];
  for (auto i = -100; i <= 100 && K; ++i) {
    if (cnt[i + 100]) {
      auto k = i < 0 ? min(K, cnt[i + 100]) : K % 2;
      cnt[-i + 100] += k;
      cnt[i + 100] -= k;
      K = i < 0 ? K - k : 0;
    }
  }
  return accumulate(begin(cnt), end(cnt), 0, [&](int s, int cnt) { return s + cnt * j++; });
}
};
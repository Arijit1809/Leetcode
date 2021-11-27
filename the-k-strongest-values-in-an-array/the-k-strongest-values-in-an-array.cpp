class Solution {
public:
        vector<int> getStrongest(vector<int> A, int k) {
        sort(A.begin(), A.end());
        int n = A.size(), i = 0, j = n - 1, m = A[(n - 1) / 2];
        while (k--) {
            if (A[j] - m >= m - A[i])
                j--;
            else
                i++;
        }
        A.erase(A.begin() + i, A.begin() + j + 1);
        return A;
    }
};
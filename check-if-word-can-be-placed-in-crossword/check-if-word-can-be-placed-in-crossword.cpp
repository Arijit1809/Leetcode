class Solution {
    bool same(vector<char> &A, int start, int end, string &s) { // returns true if `A[start..(end-1)]` equals `s` or reversed `s`.
        if (end - start != s.size()) return false;
        int j = 0;
        while (start + j < end && (A[start + j] == ' ' || A[start + j] == s[j])) ++j; // match from left to right
        if (j == s.size()) return true;
        j = 0;
        while (end - 1 - j >= start && (A[end - 1 - j] == ' ' || A[end - 1 - j] == s[j])) ++j; // match from right to left
        return j == s.size();
    }
    bool match(vector<vector<char>> &A, string s) { // returns `true` if matrix `A` matches string `s` horizontally
        int M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            int j = 0;
            while (j < N) {
                while (j < N && A[i][j] == '#') ++j;
                int start = j;
                while (j < N && A[i][j] != '#') ++j;
                if (same(A[i], start, j, s)) return true; // match `A[i][start..(j-1)]` with `s`.
            }
        }
        return false;
    }
public:
    bool placeWordInCrossword(vector<vector<char>>& A, string s) {
        int M = A.size(), N = A[0].size();
        vector<vector<char>> B(N, vector<char>(M)); // `B` is the transpose of `A`
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++ j) {
                B[j][i] = A[i][j];
            }
        }
        return match(A, s) || match(B, s);
    }
};
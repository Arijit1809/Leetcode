 class Solution {
public:
    int maxSideLength(vector<vector<int>> &mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
		
	/* Prefix sum */
		// sums[i][j] = mat[0][0] + ... + mat[i-1][j-1]
        vector<vector<int>> sums(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                sums[i][j] = mat[i - 1][j - 1] + sums[i][j - 1] + sums[i - 1][j] - sums[i - 1][j - 1];
				
	/* Binary search upper bound */
		// Possible side length: [0, min(m,n)]
        int l = 0, r = min(m, n);
        while (l < r) {
            int mid = (l + r) / 2 + (l + r) % 2;
            bool smaller = false;
            for (int i = 0; i <= m - mid && !smaller; i++)
                for (int j = 0; j <= n - mid && !smaller; j++)
					// Sum of submatrix mat[i...i+mid-1][j...j+mid-1]
                    smaller = sums[i+mid][j+mid] - sums[i+mid][j] - sums[i][j+mid] + sums[i][j] <= threshold;
            if (smaller) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
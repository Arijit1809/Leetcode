class Solution {
public:
    int maximalSquare(vector<vector<char>>& M) {
        int m = size(M), n = size(M[0]), ans = 0;        
        for(int i = m-1; ~i; i--)
            for(int j = n-1; ~j; j--) 
                if(i == m-1 or j == n-1)
                    ans = max(ans, int(M[i][j] -= '0'));
                else
                    M[i][j] = (M[i][j] == '1' ? 1+min({M[i+1][j], M[i][j+1], M[i+1][j+1]}) : 0),
                    ans = max(ans, int(M[i][j]));

        return ans * ans;
    }
};
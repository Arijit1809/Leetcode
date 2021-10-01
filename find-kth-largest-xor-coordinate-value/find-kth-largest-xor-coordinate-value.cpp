class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n =matrix.size();
        int m = matrix[0].size();
        priority_queue<int> pq;
        vector<vector<int>> A(n+1, vector<int>(m+1, 0));
        for(int i=0; i<n; i++)
        {
            for(int j= 0;j<m; j++){
                A[i+1][j+1] = matrix[i][j] ^ A[i][j] ^ A[i+1][j] ^ A[i][j+1];
                pq.push(A[i+1][j+1]);       
            }
        }
        int res = 0;
        while(!pq.empty() && k > 0){
            res = pq.top();
            pq.pop();
            k--;
        }
        return res;
    }
};
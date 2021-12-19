class Solution {
public:
    long long getDescentPeriods(vector<int>& A) {
        long long ans=0, N = A.size();
        for( long long i =0;i<N; ){
            long long len = 1;
            ++i;
            while( i<N && A[i] == A[i-1]-1) ++len,++i;
            ans += (1 + len) * len / 2;
        }
        return ans;
    }
};
class Solution {
public:
    int climbStairs(int n) {
        // if(n<0) return 0;
        // if(n==0) return 1;
        // return climbStairs(n-1) + climbStairs(n-2);
        vector<int> v(n+1);
        v[0] = 1;
        v[1] = 2;
        for(int i = 2; i<n;i++){
            v[i] = v[i-1]+v[i-2];
        }
        return v[n-1];
    }
};
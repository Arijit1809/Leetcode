class Solution {
private:
    vector<vector<int>> dp;
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size()+1,vector<int>(nums2.size()+1,-1));
        return rec(nums1,nums2,nums1.size()-1,nums2.size()-1);
    }
    
    int rec(vector<int>& nums1, vector<int>& nums2,int n1, int n2){
        if(n1<0||n2<0) return 0;
        if(dp[n1+1][n2+1]!=-1) return dp[n1+1][n2+1];
        if(nums1[n1]==nums2[n2]){
            return dp[n1+1][n2+1] = 1 + rec(nums1,nums2,n1-1,n2-1);
        }else{
            return dp[n1+1][n2+1] = max(rec(nums1,nums2,n1-1,n2),rec(nums1,nums2,n1,n2-1));
        }
    }
};
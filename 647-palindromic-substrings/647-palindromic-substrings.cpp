class Solution {
public:
    int dp[1000][1000];
    int countSubstrings(string s) {
        int n = s.size(),c=0;
        memset(dp,-1,sizeof(dp));
        for(int i = 0; i < n; i++){
            for(int j = i;j < n; j++){
                int h = helper(s,i,j);
                c+=h;
            }
        }
        return c;
    }
    
    int helper(string s,int i, int j){
        if(dp[i][j]!=-1) return dp[i][j];
        bool isP = true;
        while(i<j){
            if(s[i]==s[j] && dp[i][j]!=-1) return dp[i][j];
            else if(s[i]!=s[j]){
                isP = false;
                break;
            }
            i++;j--;
        }
        return dp[i][j] = isP;
    }
};
class Solution {
public:
    int maxPower(string s) {
        int ans = INT_MIN, now = 1;
        for(int i = 0;i<s.length();i++){
            if(i+1<s.length()&&s[i]==s[i+1]){
                now++;
            }else{
                ans = max(ans,now);
                now = 1;            
            }
        }
        return ans;
    }
};
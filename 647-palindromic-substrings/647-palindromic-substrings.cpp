class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(),c=0;
        for(int i = 0; i < n; i++){
            for(int j = i;j < n; j++){
                int h = helper(s,i,j);
                c+=h;
            }
        }
        return c;
    }
    
    bool helper(string s,int i, int j){
        bool isP = true;
        while(i<j){
            if(s[i]!=s[j]){
                isP = false;
                break;
            }
            i++;j--;
        }
        return isP;
    }
};
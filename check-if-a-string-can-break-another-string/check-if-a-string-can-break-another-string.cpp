class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool result1 = true;
        bool result2 = true;
        for(int i = 0;i<s1.length();i++){
            if(s1[i]<s2[i]){
                result1 = false;
            }
        }
        for(int i = 0;i<s1.length();i++){
            if(s1[i]>s2[i]){
                result2 = false;
            }
        }
        return result1||result2;
    }
};
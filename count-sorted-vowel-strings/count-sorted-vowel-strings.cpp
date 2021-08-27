class Solution {
public:
    int countVowelStrings(int n) {
        return rec(0,n);
    }
    
    int rec(int i,int n){
        if(i>=5) return 0;
        if(n==0){
            return 1;
        }
        return rec(i,n-1)+rec(i+1,n);
    }
};
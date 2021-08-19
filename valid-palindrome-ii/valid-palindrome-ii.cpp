class Solution {
public:
    bool validPalindrome(string s) {
        int m = s.size();
        if(m<=2) return true;
        int L,R;    
        L = 0;
        R = m-1;
        
        while(L<=R)
        {
            if(s[L]==s[R])
            {
                ++L;--R;
            }
            else 
            {
                int LL = L+1, LR = R;
                while(LL<=LR && s[LL]==s[LR]) {++LL;--LR;}
                if(LL>=LR) return true;
                
                int RL = L, RR = R-1;
                while(RL<=RR && s[RL]==s[RR]) {++RL;--RR;}
                if(RL>=RR) return true;

                return false;

            }
 
        }
        
        return true;
    }
};
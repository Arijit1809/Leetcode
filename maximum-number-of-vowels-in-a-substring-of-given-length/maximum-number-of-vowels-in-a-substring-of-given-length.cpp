class Solution {
public:
    int maxVowels(string s, int k) {
        int currCount = 0;
        int ans = 0;
        
        bool vowels[26] = {false};
        vowels[0] = vowels[4] = vowels[8] = vowels[14] = vowels[20] = true;
        
        for (int i=0; i < s.length(); i++) {
            if (i >= k and vowels[s[i-k]-'a']) {
                currCount -= 1;
            }
            if (vowels[s[i]-'a']) {
                currCount += 1;
            }
            ans = max (ans, currCount);
        }
        
        return ans ;
    }
};
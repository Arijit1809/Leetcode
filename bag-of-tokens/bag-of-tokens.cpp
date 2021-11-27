class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int l = 0;
        int r = tokens.size() - 1;
        int score = 0;
        int maxScore = 0;
        while (l <= r) {
            if (P >= tokens[l]) {
                P -= tokens[l++];
                score++;
                maxScore = max(score, maxScore);
            }
            else if (score > 0) {
                P += tokens[r--];
                score--;
            }            
            else {
                return maxScore;
            }
        }
        return maxScore;
    }
};
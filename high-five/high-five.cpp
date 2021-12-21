class Solution {
private:
    int K;

public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        this->K = 5;
        map<int, priority_queue<int, vector<int>, greater<int>>> allScores;
        for (const auto &item: items) {
            int id = item[0];
            int score = item[1];
            // insert the score in the min heap
            allScores[id].push(score);
            // remove the minimum element from the min heap in case the size of the min heap exceeds 5 
            if (allScores[id].size() > this->K)
                allScores[id].pop();
        }
        vector<vector<int>> solution;
        for (auto &[id, top_scores]: allScores) {
            int total = 0;
            // min heap contains the top 5 scores
            for (int i = 0; i < this->K; ++i) {
                total += top_scores.top();
                top_scores.pop();
            }
            solution.push_back({id, total / this->K});
        }
        return solution;
    }
};
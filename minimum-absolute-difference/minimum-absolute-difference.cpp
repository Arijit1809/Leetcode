class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minElement = *min_element(arr.begin(), arr.end());
        int maxElement = *max_element(arr.begin(), arr.end());
        int shift = -minElement;
        vector<uint8_t> line(maxElement - minElement + 1);
        vector<vector<int>> answer;
        for (const int& num : arr) {
            line[num + shift] = 1;
        }
        int minPairDiff = maxElement - minElement;
        int prev = 0;
        for (int curr = 1; curr <= maxElement + shift; ++curr) {
            if (line[curr] == 0) {
                continue;
            }
            if (curr - prev == minPairDiff) {
                answer.push_back({prev - shift, curr - shift});
            } else if (curr - prev < minPairDiff) {
                minPairDiff = curr - prev;
                answer = {{prev - shift, curr - shift}};
            }        
            prev = curr;
        }
        
        return answer;
    }
};
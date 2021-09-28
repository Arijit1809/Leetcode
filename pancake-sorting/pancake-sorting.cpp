class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> result;
        for(int i = 0;i < A.size();i++){
           auto maxPosition = max_element(A.begin(), A.end() - i);
           result.push_back(maxPosition  - A.begin() + 1);  
           result.push_back(A.size() - i);
           reverse(A.begin(),maxPosition+1);
           reverse(A.begin(),A.end() - i);
        }
        return result;
    }
};
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    vector<int> targetArray;
    for(int itr = 0; itr < index.size(); itr++){
        targetArray.insert(targetArray.begin()+index[itr], nums[itr]);
    }           
    return targetArray;
}
};
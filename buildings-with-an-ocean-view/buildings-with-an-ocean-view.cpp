class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        stack<int> heightStack;
        vector<int> canSeeOcean;
        heightStack.push(heights.size()-1);
        canSeeOcean.push_back(heights.size()-1);
        for(int i = heights.size()-2 ;i >=0 ; i--){
            if(heights[heightStack.top()]<heights[i]){
                heightStack.push(i);
                canSeeOcean.push_back(i);
            }
        }
        reverse(canSeeOcean.begin(),canSeeOcean.end());
        return canSeeOcean;
    }
};
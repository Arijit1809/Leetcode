class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> countNum;
        for(int num:nums){
            countNum[num]++;
            if(countNum[num]==2) return num;
        }
        return 1;
    }
};
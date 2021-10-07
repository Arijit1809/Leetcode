class Solution {
public:
    vector<int> twoSum(vector<int> &num, int target)
    {
        unordered_map<int,int> hash;
        vector<int> v;
        for(int i = 0 ; i<num.size();i++){
            hash.insert({num[i],i});
            auto it = hash.find(target-num[i]);
            if(it!=hash.end() && it->second!=i){
                v.push_back(i);
                v.push_back(it->second);
                break;
            }
        }
        return v;
    }
};
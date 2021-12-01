class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
	    set<vector<int>> result;
        vector<vector<int>> megaresult;
	    permuteRecursive(num, 0, result);
        for(auto v:result){
            megaresult.push_back(v);
        }
	    return megaresult;
    }
	void permuteRecursive(vector<int> &num, int begin,               set<vector<int>> &result)	{
		if (begin >= num.size()) {
		    // one permutation instance
		    result.insert(num);
		    return;
		}
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    // reset
		    swap(num[begin], num[i]);
		}
    }
};
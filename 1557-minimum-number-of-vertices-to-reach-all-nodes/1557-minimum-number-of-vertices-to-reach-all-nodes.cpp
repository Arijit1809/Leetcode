class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        vector<int> ds;
            for(auto it:edges){
                indegree[it[1]]++;
            }
        
        
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                ds.push_back(i);
            }
        }
        return ds;
    }
};
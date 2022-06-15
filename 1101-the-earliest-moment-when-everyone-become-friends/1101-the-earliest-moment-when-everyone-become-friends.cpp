class UnionFind {
    private:
    vector<int> root;
    public:
    UnionFind(int n) : root(n) {
        for(int i = 0 ; i< n ; i++){
            root[i] = i;
        }
    }
    int find(int node){
        if(node == root[node]) return node;
        else return root[node] = find(root[node]); //path compression
    }
    void unionSet(int node1, int node2){
        int root1 = find(node1);
        int root2 = find(node2);
        if(root1!=root2){
            root[root2] = root1;
        }
    }
    bool connected(int node1, int node2){
        return find(node1) == find(node2);
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        UnionFind ds(n);
        sort(logs.begin(),logs.end());
        int minTime = 0;
        int s = n;
        for(int i = 0; i < logs.size(); i++){
            int node1 = logs[i][1], node2 = logs[i][2];
            if(ds.connected(node1,node2)){ //already in the same friends group, connected indirectly
                // if(minTime==0) minTime = logs[i][0];
            }else{
                ds.unionSet(node1,node2);
                n--;
                minTime = logs[i][0];
            }
        }
        if(n>1) return -1;
        return minTime;
    }
};
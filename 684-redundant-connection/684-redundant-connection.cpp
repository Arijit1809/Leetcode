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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int noOfNodes = edges.size();
        UnionFind graphSet(noOfNodes);
        int noOfEdges = noOfNodes;
        for(int i = 0; i < noOfEdges; i++){
            int node1 = edges[i][0]-1, node2 = edges[i][1]-1;
            if(graphSet.connected(node1,node2)){
                vector<int> result = {node1+1,node2+1};
                return result;
            }else{
                graphSet.unionSet(node1,node2);
            }
        }
        return {0,0};
    }
};
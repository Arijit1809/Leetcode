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
    bool canSwap(string s1, string s2){
        char a, b;
        int notSame = 0;
        bool flag = false;
        for(int i = 0; i < s1.length(); i++){
            if(s1[i]!=s2[i]){
                notSame++;
                if(notSame==1){
                    a = s1[i];
                    b = s2[i];
                }else if(notSame==2){
                    if(s1[i]==b && s2[i]==a) flag = true;
                }else {
                    return false;
                }
            }
        }
        if(notSame<2) flag = true;
        return flag;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        UnionFind ds(n);
        int g = n;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j <n;j++){
                if(!ds.connected(i,j)){
                    if(canSwap(strs[i],strs[j])){
                        ds.unionSet(i,j); g--;
                    }
                }
            }
        }
        return g;
    }
};
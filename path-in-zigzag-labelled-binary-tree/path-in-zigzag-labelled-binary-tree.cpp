class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level = log2(label)+1;
        vector<int> path(level);
        bool flag = true;
        for(int i = 0 ; i< level;i++){
            if(flag || i == level-1){
               path[level-1-i] = label;
            }else{
                int currLevel = level - i;
                path[level-1-i] = pow(2,currLevel-1) + pow(2,currLevel) - 1 - label; 
            }
            flag=!flag;
            label=label/2;
        }
        return path;
    }
};
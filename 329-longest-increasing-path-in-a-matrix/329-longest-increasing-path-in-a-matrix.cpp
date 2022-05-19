class Solution {
    int dp[200][200];
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size(); //m->acc to ques
        int columns = matrix[0].size(); //n->acc to ques
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                ans=max(rec(i,j,matrix),ans);
            }
        }
        return ans;
    }
    
    int rec(int rowNum, int colNum,vector<vector<int>> &matrix){
        int u=0,l=0,d=0,r=0;
        int rows = matrix.size(); //m->acc to ques
        int columns = matrix[0].size(); //n->acc to ques
        
        if(dp[rowNum][colNum]!=-1) return dp[rowNum][colNum];
        
        int currElem = matrix[rowNum][colNum];
        //for the case of going up
        if(rowNum!=0 && matrix[rowNum-1][colNum]>currElem){
            u = rec(rowNum-1,colNum,matrix);
        }
        //down
        if(rowNum!=rows-1 && matrix[rowNum+1][colNum]>currElem){
            d = rec(rowNum+1,colNum,matrix);
        }
        //left
        if(colNum!=0 && matrix[rowNum][colNum-1]>currElem){
            l = rec(rowNum,colNum-1,matrix);
        }
        //right
        if(colNum!=columns-1 && matrix[rowNum][colNum+1]>currElem){
            r = rec(rowNum,colNum+1,matrix);
        }
        
        return dp[rowNum][colNum] = 1 + max({u,l,d,r});
    }
};
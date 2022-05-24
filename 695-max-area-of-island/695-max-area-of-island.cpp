typedef vector<vector<int>> vvi;

class Solution {
public:
    vvi dir = {{1,0},{-1,0},{0,1},{0,-1}}; //up, down, right, left
    
    int maxAreaOfIsland(vvi& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        vvi visited(rows,vector<int>(columns,0));
        int area = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(grid[i][j]==1){
                    area = max(area,rec(grid, i, j, visited));
                }
            }
        }
        return area;
    }

    int rec(vvi& grid, int currRow, int currColumn, vvi& visited){
        int rows = grid.size();
        int columns = grid[0].size();
        if(currRow < 0 || currRow == rows || currColumn == columns || currColumn <0) return 0;
        if(grid[currRow][currColumn]==0 || visited[currRow][currColumn]==1) return 0;
        //else if value of cell is 1 then =>
        int area = 1;
        visited[currRow][currColumn] = 1;
        for(int i = 0; i < dir.size(); i++){ //writing dir.size() so it can be improved further for other directions
            area += rec(grid,currRow+dir[i][0],currColumn+dir[i][1],visited);
        }
        return area;
    }
};
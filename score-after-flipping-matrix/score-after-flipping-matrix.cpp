class Solution {
public:
	int matrixScore(vector<vector<int>>& grid) {
		int result = 0;
		int n = grid.size(),m = grid[0].size();
		result += (1<<(m-1))*n; //flipping each bit in the first column as its msb
		for(int i =1 ;i<m;i++){ //make sure i is not zero as we dont want anything to do with the first column
			int countOnes = 0;
			for(int j=0;j<n;j++){
				if(grid[j][i]==grid[j][0]) countOnes++;
			}
			result += (1 << (m-1-i) )*max(countOnes,n-countOnes); 
		}
		return result;
	}
};
static int x = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	cout.tie(NULL);
	return 0;
}();
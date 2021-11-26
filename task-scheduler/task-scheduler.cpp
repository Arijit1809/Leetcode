class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		unordered_map<int,int> counter;
		int maxFreq = 0;
		int taskWithMaxFreq = 0;
		for(int i = 0;i<tasks.size();i++){
			counter[tasks[i]-'A']++;
		}
		for(auto taskFreq : counter){
			if(taskFreq.second>maxFreq){
				taskWithMaxFreq=1;
				maxFreq=taskFreq.second;
			}else if(taskFreq.second==maxFreq){
				taskWithMaxFreq++;
			}
		}
        cout<<"maxFreq: "<<maxFreq<<" , taskWithMaxFreq: "<<taskWithMaxFreq<<endl;
		int gaps = maxFreq-1; //suppose its aaabbb and n = 2 then we need it like a__a__a so two gaps for a=3 hence maxFreq-1;
        cout<<"Gaps: "<<gaps<<endl;
		int gapLength = n-(taskWithMaxFreq-1);
        cout<<"GapLength: "<<gapLength<<endl;
		int emptySpaces = gaps*gapLength;
        cout<<"EmptySpaces: "<<emptySpaces<<endl;
		int availableTasks = tasks.size()-maxFreq*taskWithMaxFreq;
        cout<<"available tasks: "<<availableTasks<<endl;
		int idlesToAdd = max(0,emptySpaces-availableTasks);

		return tasks.size() + idlesToAdd;
	}
};
static int x = []() {
	std::ios::sync_with_stdio(false); 
	std::cin.tie(nullptr);
	cout.tie(NULL);
	return 0;
}();
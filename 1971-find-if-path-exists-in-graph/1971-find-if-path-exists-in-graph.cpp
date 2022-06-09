class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> visited(n);
        stack<int> stack;
        stack.push(source);
        visited[source] = 1;
        while(!stack.empty()){
            int node = stack.top();
            if(node == destination) return true;
            stack.pop();
            visited[node] = 1;
            for(auto adjNode : graph[node]){
                if(!visited[adjNode]){
                    stack.push(adjNode);
                }
            }
        }
        return false;
    }
};
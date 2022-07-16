class Graph { 
private: 
    int nodes;
    vector<vector<int>> adjList;
    vector<int> indegree;
    vector<int> toposort;
public:
    Graph(int numOfNodes, vector<vector<int>> &edges){
        nodes = numOfNodes;
        adjList.resize(numOfNodes);
        indegree.resize(numOfNodes,0);
        for(vector<int> edge:edges){
            int edgeFrom = edge[1];
            int edgeTo = edge[0];
            adjList[edgeFrom].push_back(edgeTo);
            indegree[edgeTo]+=1;
        }
    }
    
    bool canTopoSort(){
        vector<int> indegreeOfNodes = indegree;
        queue<int> indegreeQueue;
        for(int node = 0; node < nodes; node++){
            if(indegreeOfNodes[node]==0){
                indegreeQueue.push(node);
            }
        }
        if(indegreeQueue.empty()) return false;
        while(!indegreeQueue.empty()){
            int currNode = indegreeQueue.front();
            indegreeQueue.pop();
            toposort.push_back(currNode);
            for(int adjNode : adjList[currNode]){
                indegreeOfNodes[adjNode]-=1;
                if(indegreeOfNodes[adjNode]==0){
                    indegreeQueue.push(adjNode);
                }
            }
        }
        bool isCyclic = false;
        for(int nodeIndegree : indegreeOfNodes){
            if(nodeIndegree!=0){
                isCyclic = true;
            }
        }
        return !isCyclic;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph courses(numCourses, prerequisites);
        return courses.canTopoSort();
    }
};
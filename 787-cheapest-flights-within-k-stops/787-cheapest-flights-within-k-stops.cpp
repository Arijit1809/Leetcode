class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		// pq=(price,node,steps)
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        
		// adj=(node,price)
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        vector<int> price(n,INT_MAX);
        vector<int> steps(n,INT_MAX);
        
        price[src]=0;
        steps[src]=0;
        
        pq.push({0,src,0});
        while(!pq.empty()){
            auto [curPrice,curNode,curSteps]=pq.top();
            pq.pop();
            if(curNode==dst){return curPrice;}
            if(curSteps==k+1){continue;}
            for(auto &[newNode,newPrice]:adj[curNode]){
                int nextPrice=newPrice+curPrice;
                int nextStep=curSteps+1;
                if(nextPrice<price[newNode] || nextStep<steps[newNode]){
                    price[newNode]=nextPrice;
                    steps[newNode]=nextStep;
                    pq.push({nextPrice,newNode,nextStep});
                }
            }
            
        }
        return -1;
    }
};
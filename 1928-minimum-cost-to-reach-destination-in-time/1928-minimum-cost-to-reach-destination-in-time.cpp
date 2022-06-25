class Solution {
public:
    
    typedef array<int,3> Node; //cost, time, node
    
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<unordered_map<int,int>> adj(n);
        for(auto& edge:edges){
            int u = edge[0], v = edge[1], t = edge[2];
            if(adj[u].count(v)){
                adj[u][v] = adj[v][u] = min(t,adj[u][v]);
            }
            else adj[u][v] = adj[v][u] = t;
        }
        priority_queue<Node,vector<Node>, greater<Node>> pq;
        vector<int> minTime(n,maxTime+1);
        minTime[0] = 0;
        pq.push({passingFees[0],0,0});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int currentCost = curr[0];
            int currentTime = curr[1];
            int currentNode = curr[2];
            if(currentNode == n-1) return currentCost;
            for(auto& nb:adj[currentNode]){
                int childNode = nb.first;
                int edgeTime = nb.second;
                if(currentTime + edgeTime < minTime[childNode]){
                    minTime[childNode] = currentTime + edgeTime;
                    pq.push({currentCost+passingFees[childNode],minTime[childNode],childNode});
                }
            }
        }
        return -1;
    }
};
class Solution {
public:
   typedef vector<int> VE;
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
{
	vector<pair<int,int>>adj[n];  
	for(auto it: flights)
	{
		int u = it[0];
		int v = it[1];
		int wt = it[2];
		adj[u].push_back({v,wt});
	}

	priority_queue<VE, vector<VE>, greater<VE>> pq;
	pq.push({0,src,0});

	vector<int> dist(n+1, INT_MAX);

	while(!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		int cost = cur[0], node = cur[1], edge_steps = cur[2];
		if(node==dst) return cost;
		if(edge_steps>k) continue; 
		if(dist[node]<edge_steps) continue;
		dist[node]=edge_steps;
		for(auto it: adj[node])
		{
			int nextNode = it.first;       
			int nextNodeDist = it.second;
			pq.push({cost+nextNodeDist, nextNode, edge_steps+1});
			//Add nextnode's dist to cost, nextNode, add 1 to edge_steps
		}
	}     

	return -1;
	//if we reach here that means either there is no destination 
	//or it was taking more than k stops to reach destination
}
};
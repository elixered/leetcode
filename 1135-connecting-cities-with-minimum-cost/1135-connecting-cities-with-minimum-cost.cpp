typedef pair<int,int> pii;
class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        vector<vector<pii>> mp(N+1);
        vector<bool> visited(N+1, false);
        vector<int> minCost(N+1, INT_MAX);
        for (auto& edge : connections) {
            mp[edge[0]].push_back({edge[2], edge[1]});
            mp[edge[1]].push_back({edge[2], edge[0]});
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0,1});
        int numVisited = 0, res = 0;
        while (numVisited < N && !pq.empty()) {
            int cost = pq.top().first, city = pq.top().second;
            pq.pop();
            if (visited[city]) continue;
            visited[city] = true;
            numVisited++;
            res += cost;
            for (auto& n : mp[city]) {
                cost = n.first;
                city = n.second;
                if (!visited[city] && cost < minCost[city]) {
                    minCost[city] = cost;
                    pq.push({cost, city});
                }
            }
        }
        return numVisited == N ? res : -1;
    }
};
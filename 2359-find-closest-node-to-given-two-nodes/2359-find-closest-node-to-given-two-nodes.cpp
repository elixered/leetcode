class Solution {
public:
    void dfs(int i, int dist, vector<int>& e, vector<int>& memo) {
    while (i != -1 && memo[i] == -1) {
        memo[i] = dist++;
        i = e[i];
    }
}
int closestMeetingNode(vector<int>& e, int node1, int node2) {
    int res = -1, min_dist = INT_MAX;
    vector<int> m1(e.size(), -1), m2(e.size(), -1);
    dfs(node1, 0, e, m1);
    dfs(node2, 0, e, m2);
    for (int i = 0; i < e.size(); ++i)
        if (min(m1[i], m2[i]) >= 0 && max(m1[i], m2[i]) < min_dist) {
            min_dist = max(m1[i], m2[i]);
            res = i;
        }
    return res;
}
};
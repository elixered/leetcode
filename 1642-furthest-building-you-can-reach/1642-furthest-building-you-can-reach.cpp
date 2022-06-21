class Solution {
public:
    int furthestBuilding(vector<int>& hs, int bricks, int ladders) {
    priority_queue<int> pq;
    for (int i = 1; i < hs.size(); ++i) {
        int d = hs[i] - hs[i - 1];
        if (d > 0) {
            pq.push(d);
            bricks -= d;
            if (bricks < 0) {
                --ladders;
                bricks += pq.top();
                pq.pop();
                if (bricks < 0 || ladders < 0)
                    return i - 1;

            }
        }
    }
    return hs.size() - 1;
}  
};
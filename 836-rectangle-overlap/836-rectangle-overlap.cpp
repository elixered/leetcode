class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
        int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];
        
        bool overlapX = max(x1,x3) < min(x2,x4);
        bool overlapY = max(y1,y3) < min(y2,y4);
        
        return overlapX && overlapY;
    }
};
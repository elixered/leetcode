class Solution {
public:
    
    
    
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a = (ax1-ax2)*(ay1-ay2);
        a += (bx1-bx2)*(by1-by2);
        
        if(max(ax1,bx1) < min(ax2,bx2) && max(ay1,by1) < min(ay2,by2)){
            a -= (max(ax1,bx1)-min(ax2,bx2))*(max(ay1,by1)-min(ay2,by2));
        }
        return a;
    }
};
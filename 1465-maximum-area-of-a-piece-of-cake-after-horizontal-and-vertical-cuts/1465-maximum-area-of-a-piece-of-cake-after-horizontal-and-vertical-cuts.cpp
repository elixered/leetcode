class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(begin(hc),end(hc));
        sort(begin(vc),end(vc));
        int m1 = 0, prev = 0;
        for(auto l:hc){
            m1 = max(m1,l-prev);
            prev = l;
        }
        m1 = max(h-prev,m1);
        int m2 = 0;
        prev = 0;
        for(auto l:vc){
            m2 = max(m2,l-prev);
            prev = l;
        }
        m2 = max(w-prev,m2);
        int m = pow(10,9)+7;
        return ((long)m1*m2)%m;
    }
};
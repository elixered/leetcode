class Solution {
public:
    vector<int> p;
    Solution(vector<int>& w) {
        p = w;
        for(int i=1; i<p.size(); i++)
            p[i] += p[i-1];
    }
    
    int pickIndex() {
        int m = p.back();
        int r = rand()%m+1;
        return lower_bound(p.begin(),p.end(),r)-p.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
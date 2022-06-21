class Solution {
public:
int monoStack(int h, vector<int> &ms) {
    int res = 0;
    while(!ms.empty() && ms.back()<h){
        ms.pop_back();
        res++;
    }
    res += !ms.empty();
    if(ms.empty() or ms.back()!=h)
    ms.push_back(h);
    return res;
}
vector<vector<int>> seePeople(vector<vector<int>>& h) {
    int m = h.size(), n = h[0].size();
    vector<vector<int>> res(m, vector<int>(n)), hms(m), vms(n); 
    for (int i = m - 1; i >= 0; --i)
        for (int j = n - 1; j >= 0; --j)
            res[i][j] = monoStack(h[i][j], hms[i]) + monoStack(h[i][j], vms[j]);
    return res;
}
};
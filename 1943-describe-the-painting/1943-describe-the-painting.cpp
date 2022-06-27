class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
    long long mix[100002] = {}, sum = 0;
    bool ends[100002] = {};
    vector<vector<long long>> res;
    for (auto &s : segments) {
        mix[s[0]] += s[2];
        mix[s[1]] -= s[2];
        ends[s[0]] = ends[s[1]] = true;
    }
    for (int i = 1; i < 100002; ++i) {
        sum += mix[i];
        if(ends[i] && sum){
            int j = i+1;
            while(j < 100002 && !ends[j]){
                sum += mix[j];
                j++;
            }
            if(j!=100002)
            res.push_back({i,j,sum});
            i = j-1;
        }
    }
    return res;
}
};
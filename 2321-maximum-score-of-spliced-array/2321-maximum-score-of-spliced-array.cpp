class Solution {
public:
int maximumsSplicedArray(vector<int>& n1, vector<int>& n2) {
    int sum1 = 0, res1 = 0, sum2 = 0, res2 = 0;
    for (int i = 0; i < n1.size(); ++i) {
        sum1 = max(n2[i] - n1[i], sum1 + n2[i] - n1[i]);
        res1 = max(res1, sum1);
        sum2 = max(n1[i] - n2[i], sum2 + n1[i] - n2[i]);
        res2 = max(res2, sum2);        
    }    
    return max(accumulate(begin(n1), end(n1), 0) + res1, accumulate(begin(n2), end(n2), 0) + res2);
}

};
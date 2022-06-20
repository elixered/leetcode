class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int res = 1;
        unordered_map<int,int> maxmap;
        for(int i = 0 ; i < arr.size() ; i++)
            maxmap[arr[i]] = maxmap[arr[i]-diff]+1;
        for(auto it : maxmap)
            res = max(res,it.second);
        return res;
    }
};
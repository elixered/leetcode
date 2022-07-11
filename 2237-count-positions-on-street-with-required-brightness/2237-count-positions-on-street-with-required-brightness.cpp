class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
        vector<int> brightness(n + 1, 0);
        for (auto& l : lights)
        {
            brightness[max(0, l[0] - l[1])]++;
            brightness[min(n, l[0] + l[1] + 1)]--;
        }
        int bright = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            bright += brightness[i];
            if (bright >= requirement[i])
                ans++;
        }
        return ans;
    }
};
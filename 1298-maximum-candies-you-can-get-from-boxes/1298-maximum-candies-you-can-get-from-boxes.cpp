class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& boxes) {
        bool changed = true;
        int ans = 0;
        while(!boxes.empty() && changed)
        {
            changed = false;
            vector<int> newBoxes;
            for(auto b:boxes)
            {
                if(status[b])
                {
                    changed = true;
                    newBoxes.insert(end(newBoxes),containedBoxes[b].begin(),containedBoxes[b].end());
                    for(auto k:keys[b])
                        status[k] = 1;
                    ans += candies[b];
                }
                else newBoxes.push_back(b);
            }
            swap(boxes,newBoxes);
        }
        return ans;
    }
};
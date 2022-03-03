class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        vector<int> vis(n,0);
        int k = n-1;
        int max = *max_element(arr.begin(),arr.end());
        int min = *min_element(arr.begin(),arr.end());
        if(max==min) return true;
        if((max-min)%k!=0) return false;
        int diff = (max-min)/k;
        for(auto it:arr)
        {
            if((it-min)%diff!=0) return false;
            int p = (it-min)/diff;
            if(vis[p]) return false;
            else vis[p] = 1;
        }
        return true;
    }
};
class Solution {
public:
    
    int upper(vector<vector<int>>& tiles, int e)
    {
        int low = 0;
        int high = tiles.size()-1;
        int ans = tiles.size();
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(tiles[mid][1]>e)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    
    int maximumWhiteTiles(vector<vector<int>>& tiles, int k) {
        sort(tiles.begin(),tiles.end());
        int n = tiles.size();
        vector<int> p(n);
        p[0] = tiles[0][1]-tiles[0][0]+1;
        for(int i=1; i<n; i++)
            p[i] += p[i-1] + tiles[i][1]-tiles[i][0]+1;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int s = tiles[i][0];
            int e = s+k-1;
            int idx = upper(tiles,e);
            int curr = idx==0?0:p[idx-1];
            if(i!=0)
                curr -= p[i-1];
            if(idx!=n)
                curr += max(0,e-tiles[idx][0]+1);
            ans = max(ans,curr);
        }
        return ans;
    }
};
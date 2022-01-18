class Solution {
public:
    bool canPlaceFlowers(vector<int>& flower, int k) {
        int n = flower.size();
        if(k>(n+1)/2)
            return false;
        int res = 0;
        for(int i=0; i<n; i++)
        {
            if(flower[i]==1)
                continue;
            int j = i;
            while(j<n && flower[j]==flower[i])
                j++;
           int total = j-i;
            if(i!=0)
                total--;
            if(j!=n)
                total--;
            res += (total+1)/2;
            i = j-1;
        }
        return res>=k;
    }
};
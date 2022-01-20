class Solution {
public:
    bool suitable(vector<int>& piles, int h, int speed)
    {
        int tot = 0;
        for(auto it:piles)
            tot += ceil(it/((double)speed));
        return tot<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = pow(10,9);
        int low = 1;
        int ans = high;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(suitable(piles,h,mid))
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};
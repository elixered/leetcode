class Solution {
int BIT[100002], m;
void update(int x, int delta)
{
      for(; x <= m; x += x&-x)
        BIT[x] += delta;
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}
public:
    bool isIdealPermutation(vector<int>& nums) {
        int local = 0;
        int global = 0;
        int n = nums.size();
        m = n+2;
        for(int i=0; i<n; i++)
        {
            if(i<n-1 && nums[i]>nums[i+1])
                local++;
            global += query(m-1)-query(nums[i]);
            if(global>n) return false;
            update(nums[i]+1,1);
        }
        return global == local;
    }
};
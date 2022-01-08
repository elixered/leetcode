class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(n!=1)
        {
            int x = n;
            int sum = 0;
            while(x>0)
            {
                int rem = x%10;
                x = x/10;
                sum += rem*rem;
            }
            if(sum==1) return true;
            if(set.count(sum)>0) return false;
            set.insert(sum);
            n = sum;
        }
        return true;
    }
};
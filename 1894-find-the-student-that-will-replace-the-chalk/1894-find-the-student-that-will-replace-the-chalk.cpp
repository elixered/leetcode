class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum  = 0;
        int n = chalk.size();
        for(auto& it:chalk)
            sum += it;
        k = k%sum;
        for(int i=0; i<n; i++)
        {
            if(k<chalk[i])
                return i;
            else k-=chalk[i];
        }
        return 0;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int s1 = accumulate(begin(nums1),end(nums1),0);
        int s2 = accumulate(begin(nums2),end(nums2),0);
        if(n1 > n2*6 or n2 > n1*6) return -1;
        if(s1 > s2) return minOperations(nums2,nums1);
        vector<int> count1(7,0),count2(7,0);
        for(auto it:nums1)
            count1[it]++;
        for(auto it:nums2)
            count2[it]++;
        int ans = 0;
        for(int i=1; i<=5; ++i){
            while(count1[i]--){
                if(s1==s2) return ans;
                if(s2 - s1 <= 6-i) return ans+1;
                else s1 += 6-i;
                ans++;
            }
            int i2 = 7-i;
            while(count2[i2]--){
                if(s1==s2) return ans;
                if(s2 - s1 <= i2-1) return ans+1;
                else s1 += i2-1;
                ans++;
            }
        }

        return s1 == s2 ? ans:-1;
    }
};
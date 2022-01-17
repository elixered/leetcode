class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int i=0,j=0;
        unordered_map<int,int> map1,map2;
        for(int k=0; k<nums1.size(); k++)
            if(map1.find(nums1[k])==map1.end())
                map1[nums1[k]] = k;
        for(int k=0; k<nums2.size(); k++)
            map2[nums2[k]] = k;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]>nums2[j])
                j++;
            else 
            {
                ans = max(ans,map2[nums2[j]]-map1[nums1[i]]);
                i++;
            }
        }
        return ans;
    }
};
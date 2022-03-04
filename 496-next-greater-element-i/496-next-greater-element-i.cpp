class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        for(int i=0; i<nums2.size(); i++)
            map[nums2[i]] = i;
        stack<int> st;
        st.push(-1);
        for(int i=nums2.size()-1; i>=0; i--)
        {
            int curr = nums2[i];
            while(st.size()>1 && curr>st.top())
                st.pop();
            nums2[i] = st.top();
            st.push(curr);
        }
        for(int i=0; i<nums1.size(); i++)
            nums1[i] = nums2[map[nums1[i]]];
        return nums1;
    }
};
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        stack<char> st;
        vector<int> freq(26,0);
        vector<int> seen(26,0);
        for(auto c:s)
            freq[c-'a']++;
        for(int i=0; i<n; i++)
        {
            char ch = s[i];
            freq[ch-'a']--;
            if(seen[ch-'a']) continue;
            while(st.size()>0 && st.top() > ch && freq[st.top()-'a'] > 0)
            {
                seen[st.top()-'a'] = 0;
                st.pop();
            }
            seen[ch-'a']++;
            st.push(ch);
        }
        string ans = "";
        while(st.size() != 0){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
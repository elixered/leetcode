class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            if(s[i]==' ')
                continue;
            int j = i;
            while(j<n && s[j]!=' ')
                j++;
            int next = j;
            j--;
            while(i<=j)
                swap(s[i++],s[j--]);
            i = next;
        }
        return s;
    }
};
class Solution {
public:
    int isPrefixOfWord(string sentence, string word) {
        string s = word + " " + sentence;
        int n = s.size();
        vector<int> z(n,0);
        int l=0,r=0;
        for(int i=1; i<n; ++i){
            if(i<=r)
                z[i] = min(r-i+1,z[i-l]);
            while(i+z[i]<n && s[z[i]] == s[i+z[i]])
                ++z[i];
            if(i+z[i]-1 > r)
                l=i,r=i+z[i]-1;
        }
        int count = 1;
        for(int i=word.size()+1; i<n; ++i){
            if(z[i] >= word.size() && s[i-1] == ' ')
                return count;
            else if(s[i] == ' ')
                count++;
        }
        return -1;
    }
};
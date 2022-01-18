class Solution {
public:
    
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        string v = "aeiouAEIOU";
        unordered_set<char> vowel(v.begin(),v.end());
        while(i<j)
        {
            if(vowel.find(s[i])==vowel.end())
                i++;
            else if(vowel.find(s[j])==vowel.end())
                j--;
            else swap(s[i++],s[j--]);
        }
        return s;
    }
};
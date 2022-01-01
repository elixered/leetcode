class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        string word;
        int count = 0;
        while(getline(ss,word,' '))
        {
            if(word.size()!=0)
                count++;
        }
        return count;
    }
};
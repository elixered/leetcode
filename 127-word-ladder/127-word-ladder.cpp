class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {  
        unordered_set<string> words(wordList.begin(),wordList.end());
        if(words.find(endWord)==words.end()) return 0;
        unordered_set<string> begin;
        unordered_set<string> end;
        begin.insert(beginWord);
        end.insert(endWord);
        int count = 1;
        while(!begin.empty() && !end.empty())
        {
            count++;
            if(begin.size()>end.size())
                swap(begin,end);
            unordered_set<string> tbeg;
            for(auto s:begin)
            {
                for(int i=0; i<s.size(); i++)
                {
                    char temp = s[i];
                    for(char ch='a'; ch<='z'; ch++)
                    {
                        s[i] = ch;
                        if(end.find(s)!=end.end())
                            return count;
                        if(words.find(s)!=words.end())
                        {
                            words.erase(s);
                            tbeg.insert(s);
                        }
                        s[i] = temp;
                    }
                }
            }
            begin = tbeg;
        }
        return 0;
    }
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(),wordList.end());
        queue<string> q;
        if(words.find(endWord)==words.end())
            return 0;
        int count = 0;
        q.push(beginWord);
        while(!q.empty())
        {
            count++;
            int n = q.size();
            for(int k=0; k<n; k++)
            {
                auto s = q.front();
                q.pop();
                if(s==endWord) return count;
                for(int i=0; i<s.size(); i++)
                {
                    char temp = s[i];
                    for(char ch='a'; ch<='z'; ch++)
                    {
                        s[i] = ch;
                        if(words.find(s)==words.end()) continue;
                        {
                            q.push(s);
                            words.erase(s);
                        }
                    }
                    s[i] = temp;
                }
            }
        }
        return 0;
    }
};
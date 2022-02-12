class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(),wordList.end());
        queue<string> q;
        if(words.find(endWord)==words.end())
            return 0;
        int count = 0;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
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
                        if(visited.find(s)!=visited.end() or words.find(s)==words.end()) continue;
                        {
                            q.push(s);
                            visited.insert(s);
                        }
                    }
                    s[i] = temp;
                }
            }
        }
        return 0;
    }
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> set(wordList.begin(),wordList.end());
        if(set.find(endWord)==set.end())
            return 0;
        int count = 1;
        while(!q.empty())
        {
            int total = q.size();
            for(int k=0; k<total; k++)
            {
            auto curr = q.front();
            q.pop();
            if(curr==endWord)
                return count;
            int n = curr.size();
            for(int i=0; i<n; i++)
            {
                char temp = curr[i];
                for(char ch='a'; ch<='z'; ch++)
                {
                    curr[i] = ch;
                    if(set.find(curr)!=set.end())
                    {
                        q.push(curr);
                        set.erase(curr);
                    }
                }
                curr[i] = temp;
            }
        }
            count++;
        }
        return 0;
    }
};
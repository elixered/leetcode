class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, vector<string>& wordList) {
        vector<vector<string>> ans;
        vector<vector<string>> levels;
        unordered_set<string> words(wordList.begin(),wordList.end());
        queue<string> q;
        bool flag = false;
        if(words.find(end)==words.end()) return ans;
        q.push(start);
        levels.push_back({start});
        while(!q.empty())
        {
            int n = q.size();
            vector<vector<string>> temp;
            for(int idx=0; idx<n; idx++)
            {
                vector<string> curr = levels[idx];
                unordered_set<string> prev(levels[idx].begin(),levels[idx].end());
                auto s = q.front();
                q.pop();
                for(int i=0; i<s.size(); i++)
                {
                    char d = s[i];
                    for(char ch='a'; ch<='z'; ch++)
                    {
                        if(ch==d) continue;
                        s[i] = ch;
                        if(s==end)
                        {
                            flag = true;
                            curr.push_back(s);
                            temp.push_back(curr);
                            curr.pop_back();
                        }
                        else
                        if(words.find(s)!=words.end())
                        {
                            curr.push_back(s);
                            temp.push_back(curr);
                            curr.pop_back();
                            q.push(s);
                        }
                        s[i] = d;
                    }
                }
                words.erase(s);
            }
            levels = temp;
            if(flag) break;
        }
        for(auto it:levels)
        {
            if(it.back()==end)
                ans.push_back(it);
        }
        
        return ans;
    }
};
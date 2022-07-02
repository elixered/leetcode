class WordDistance {
public:
    unordered_map<string,vector<int>> mp;
    WordDistance(vector<string>& wordsDict) {
        for(int i=0; i<wordsDict.size(); i++){
            mp[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int ans = INT_MAX;
        for(auto it:mp[word1]){
            for(auto it1:mp[word2])
                ans = min(ans,(int)abs(it-it1));
        }
        return ans;
    }
};
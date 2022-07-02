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
        auto& a = mp[word1];
        auto& b = mp[word2];
        int i=0,j=0;
        while(i<a.size() && j<b.size()){
            ans = min(ans,(int)abs(a[i]-b[j]));
            if(a[i] < b[j])
                i++;
            else j++;
        }
        return ans;
    }
};